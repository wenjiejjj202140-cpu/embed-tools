#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p = (int *)malloc(10*sizeof(int));

    if(p == NULL){
        printf("内存分配失败！\n");
        return 1;//为什么要返回1 ?
    }

    for(int i = 0; i<10; i++){
        p[i] = i + 1;
    }

    for(int i = 0; i<10; i++){
        printf("p[%d] = %d\n", i, p[i]);
    }
    free(p);
    p = NULL;
    return 0;
}