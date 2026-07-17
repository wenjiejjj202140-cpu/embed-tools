#include <stdio.h>

int main() {
    // 任务1: 声明 int 变量 num = 10
    // ↓
    int num = 10;
    // 任务2: 声明指针 p，指向 num
    // ↓
    int *p = &num;
    // 任务3: 打印 num 的值
    // ↓
    printf("num值 = %d\n",num);
    // 任务4: 打印 num 的地址
    // ↓
    printf("num地址 = %p\n",p);
    // 任务5: 打印 p 的值（存的地址）
    // ↓
    printf("p的值 = %p\n",p);
    // 任务6: 通过 p 把 num 改成 99
    // ↓
    *p = 99;
    // 任务7: 打印修改后的 num
    // ↓
    printf("改后的num值 = %d\n",num);
    return 0;
}