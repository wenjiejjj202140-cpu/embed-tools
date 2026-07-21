#include <stdio.h>

// ---- 你的代码写在这里 ----
// 定义函数指针类型: CmpFunc，指向"接收两个int、返回int"的函数
// 提示：typedef int (*__)(int, int);
typedef int (*CmpFunc)(int, int);//怎么判断你是需要指针函数还是普通函数？

// 定义 max 函数：返回两个数中较大的
int max(int a,int b){
     return a - b;
}

// 定义 min 函数：返回两个数中较小的
int min(int a,int b){
     return b - a;
}

// ---- 回调函数 ----
// compare(a, b, cmp) 接收两个数和比较器，返回比较结果
// 如果 cmp(a,b) > 0，打印 "a 大"
// 如果 cmp(a,b) < 0，打印 "b 大"
// 如果 cmp(a,b) == 0，打印 "相等"
// 最后返回 cmp(a,b) 的结果
int compare(int a, int b, CmpFunc cmp) {  // ← 填空1：函数指针参数
    int result = cmp(a, b);       // ← 填空2：通过回调调比较函数
    
    if (result > 0) {                    // ← 填空3：判断
        printf("a 大\n");
    } else if (result < 0) {
        printf("b 大\n");
    } else {
        printf("相等\n");
    }
    
    return result;
}

int main() {
    int x = 7, y = 3;
    
    printf("比较 %d 和 %d（用 max）:\n", x, y);
    int result1 = compare(x, y, max);  // ← 填空4：调用 compare
    printf("结果: %d\n\n", result1);
    
    printf("比较 %d 和 %d（用 min）:\n", x, y);
    int result2 = compare(x, y, min);
    printf("结果: %d\n", result2);
    
    return 0;
}