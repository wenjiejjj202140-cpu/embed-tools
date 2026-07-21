#include <stdio.h>
#include <stdarg.h>

void my_printf(const char *fmt, ...) {
    va_list ap;
    ______(ap, fmt);        // 填空1：初始化
    
    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] == '%') {
            i++;  // 跳过 %
            switch (fmt[i]) {
                case 'd': {
                    int val = ______(ap, int);  // 填空2：取一个 int
                    printf("%d", val);
                    break;
                }
                case 'c': {
                    char ch = ______(ap, int);  // 填空3：char 在变参中提升为 int
                    putchar(ch);
                    break;
                }
                default:
                    putchar(fmt[i]);
            }
        } else {
            putchar(fmt[i]);
        }
    }
    
    ______(ap);  // 填空4：清理
}

int main() {
    my_printf("姓名: %c, 年龄: %d, 分数: %d\n", '文', 21, 95);
    // 预期输出：姓名: 文, 年龄: 21, 分数: 95
    return 0;
}