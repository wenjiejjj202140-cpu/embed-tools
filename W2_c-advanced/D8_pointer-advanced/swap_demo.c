#include <stdio.h>

// 函数：交换两个 int* 指针指向的对象
void swap_int_ptr(int **a, int **b) {
    int *temp = *a;   // 暂存 p（int*）
    *a = *b;          // p 指向 y
    *b = temp;        // q 指向原来 p 指向的 x
}

int main() {
    int x = 10, y = 20;
    int *p = &x, *q = &y;
    
    printf("交换前: *p=%d, *q=%d\n", *p, *q);
    swap_int_ptr(&p, &q);
    printf("交换后: *p=%d, *q=%d\n", *p, *q);  // 期望 20, 10
    
    return 0;
}
