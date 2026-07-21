#include <stdio.h>

// 定义一个函数类型 PrintType，指向"接收一个 int 参数、返回 void"的函数
typedef void (*PrintType)(int); // ← 用 typedef 定义 PrintType

void print_star(int n) {
    for (int i = 0; i < n; i++) putchar('*');
    putchar('\n');
}

void print_dash(int n) {
    for (int i = 0; i < n; i++) putchar('-');
    putchar('\n');
}

int main() {
    PrintType p1 = print_star; // ← 用类型别名声明
    PrintType p2 = print_dash;

    p1(5);  // 输出 *****
    p2(8);  // 输出 --------
    return 0;
}