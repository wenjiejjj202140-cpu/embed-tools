#include <stdio.h>
#include <stdlib.h>

// ---- 你的代码 ----
// 写一个比较函数 cmp_float，按 float 值升序
// 提示：需要把 const void* 转成 const float*，然后比较
int cmp_float(const void *a, const void *b) {
    float fa = *(const float *)a;
    float fb = *(const float *)b;

    if (fa>fb) return -1;   // 大的排在前面
    if (fa<fb) return 1;    // 小的排在后面
    return 0;                 // 相等
}

int main() {
    float arr[] = {3.14, 1.5, 2.71, 0.618, 9.99};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    qsort(arr,n,sizeof(arr[0]),cmp_float);  // ← 填空：调用 qsort
    
    for (int i = 0; i < n; i++)
        printf("%.3f ", arr[i]);
    printf("\n");
    // 预期：0.618 1.500 2.710 3.140 9.990
    return 0;
}