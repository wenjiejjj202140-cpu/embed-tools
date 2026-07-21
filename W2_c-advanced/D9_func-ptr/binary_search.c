#include <stdio.h>

// 实现二分查找，找到返回下标，未找到返回 -1
int binary_search(int arr[], int n, int target) {
    // 你的代码
    int right = n-1;
    int left = 0;
    
    while(left <= right){
        int mid = left+(right-left)/2;
        if(target<*(arr+mid)){
        right = mid-1;
        }else if(target>*(arr+mid)){
        left  = mid+1;
        }else{
            return mid;//这样行不行？
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int idx1 = binary_search(arr, n, 23);
    printf("23 在位置: %d\n", idx1);  // 预期输出：5
    
    int idx2 = binary_search(arr, n, 99);
    printf("99 在位置: %d\n", idx2);  // 预期输出：-1
    
    return 0;
}

// 提示：
// 用三个变量：left（左边界）、right（右边界）、mid（中间位置）
// while 循环，条件是 left <= right
// mid 的计算防溢出：left + (right - left) / 2