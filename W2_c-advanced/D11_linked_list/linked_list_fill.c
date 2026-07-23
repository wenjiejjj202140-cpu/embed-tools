#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;  // 填空1
};

int main() {
    struct Node *n1 = malloc(sizeof(struct Node));  // 填空2
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;  // 填空3：n1→n2
    n2->next = n3;  // 填空4：n2→n3
    n3->next = NULL;  // 填空5：尾节点

    struct Node *cur = n1;  // 填空6：从 head 开始
    while (cur != NULL) {     // 填空7：循环条件
        printf("%d ", cur->data);
        cur = cur->next;     // 填空8：移动
    }
    printf("\n");

    free(n3);
    free(n2);
    free(n1);
    return 0;
}