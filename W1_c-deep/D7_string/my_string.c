// my_string.c — D7 字符串处理
// 功能：安全版字符串复制和拼接（带长度限制）
// 编译：gcc -Wall -Wextra my_string.c -o my_string && ./my_string

#include <stdio.h>

// ─── my_strcpy ─────────────────────────────────────────────
// 功能：把 src 拷贝到 dest，最多拷贝 dest_size-1 个字符
// 返回值：复制的字符数（不含 \0）
// 约定：dest 最后一位总是 \0
int my_strcpy(char *dest, const char *src, int dest_size) {
    int count = 0;
    for(int i = 0; i < dest_size - 1; i++){
        dest[i] = src[i];
        if(src[i] == '\0') break;
        count++;
    }
    dest[dest_size - 1] = '\0';
    return count;
}

// ─── my_strcat ─────────────────────────────────────────────
// 功能：把 src 拼接到 dest 末尾，最多拼到 dest_size-1
// 返回值：拼接后 dest 的总字符数（不含 \0）
// 约定：dest 最后一位总是 \0
int my_strcat(char *dest, const char *src, int dest_size) {
    // 第 1 步：找到 dest 中 \0 的位置
    int i = 0;
    while(i < dest_size && dest[i] != '\0'){
        i++;
    }

    // 第 2 步：从 \0 位置开始拼接 src，留一位给 \0
    int j = 0;
    while(src[j] != '\0' && i < dest_size - 1){
        dest[i] = src[j];
        j++;
        i++;
    }

    dest[dest_size - 1] = '\0';
    return i;
}

// ─── main：测试 ────────────────────────────────────────────
int main() {

    printf("═══ my_strcpy 测试 ═══\n\n");

    // 测试 1：src 比 dest 长（截断）
    char dest1[6];
    int c1 = my_strcpy(dest1, "Hello World!", sizeof(dest1));
    printf("截断:      [%s], 复制了 %d 个\n", dest1, c1);

    // 测试 2：src 比 dest 短（正常拷贝）
    char dest2[10];
    int c2 = my_strcpy(dest2, "Hi", sizeof(dest2));
    printf("短拷贝:    [%s], 复制了 %d 个\n", dest2, c2);

    // 测试 3：空字符串
    char dest3[10];
    int c3 = my_strcpy(dest3, "", sizeof(dest3));
    printf("空字符串:  [%s], 复制了 %d 个\n", dest3, c3);

    // 测试 4：刚好能放下（"Hello" 5 字节，dest 6 字节）
    char dest4[6];
    int c4 = my_strcpy(dest4, "Hello", sizeof(dest4));
    printf("刚好放下:  [%s], 复制了 %d 个\n", dest4, c4);

    printf("\n═══ my_strcat 测试 ═══\n\n");

    // 测试 5：拼接
    char buf[10] = "Hello";
    int total = my_strcat(buf, " World!", sizeof(buf));
    printf("拼接:      [%s], 共 %d 个字符\n", buf, total);

    // 测试 6：空目标拼接
    char buf2[10] = "";
    int total2 = my_strcat(buf2, "Hi", sizeof(buf2));
    printf("空目标拼接:[%s], 共 %d 个字符\n", buf2, total2);

    return 0;
}
