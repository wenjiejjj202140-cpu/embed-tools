#include <stdio.h>

int factorial(int n) {
    // 每层递归打印自己的地址
    printf("fact(%d) 创建, &n=%p, &n_local=%p\n", 
           n, (void*)&n, (void*)&n);
    
    if (n == 0) {
        printf("fact(%d) 触底! 返回 1\n", n);
        return 1;
    }
    
    int result = n * factorial(n - 1);
    printf("fact(%d) 返回 %d\n", n, result);
    return result;
}

int main() {
    int main_local = 999;
    printf("main 的栈帧在: &main_local=%p\n\n", (void*)&main_local);
    
    factorial(4);
    
    return 0;
}