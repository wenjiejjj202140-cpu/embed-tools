#include <stdio.h>

int multiply(int x, int y) {
    return x * y;
}

int main() {
    // 声明一个函数指针 p，指向"接收两个int参数、返回int"的函数
    int (*p)(int,int); //括号里面居然还可以直接填int吗？

    p = multiply; //p就代表函数地址入口所以只用填p就行了？

    int result = (*p)(4, 7); // 这里p和*p是一样的把？

    printf("4 * 7 = %d\n", result);
    return 0;
}