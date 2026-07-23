#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// 请实现：头插法
void insert_head(struct Node **head, int value) {
    // 你的代码
    struct Node *new = malloc(sizeof(struct Node));
    new->data = value;
    new->next = *head;
    *head = new;
}

void print_list(struct Node *head) {
    struct Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    struct Node *list = NULL;  // 空链表

    insert_head(&list, 30);
    insert_head(&list, 20);
    insert_head(&list, 10);

    print_list(list);  // 应该输出：10 20 30

    // 销毁
    struct Node *cur = list;
    while (cur != NULL) {
        struct Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    return 0;
}