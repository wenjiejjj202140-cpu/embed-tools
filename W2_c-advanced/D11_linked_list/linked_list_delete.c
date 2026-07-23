#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int delete_by_value(struct Node **head, int value) {
    struct Node *prev = NULL;
    struct Node *cur = *head;

    while (cur != NULL) {
        if (cur->data == value) {
            if (prev == NULL)         // 删头节点
                *head = cur->next;
            else                      // 删其他节点
                prev->next = cur->next;
            free(cur);
            return 1;  // 找到并删除
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;  // 没找到
}

void insert_head(struct Node **head, int value) {
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

void free_list(struct Node *head) {
    struct Node *cur = head;
    while (cur != NULL) {
        struct Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

int main() {
    struct Node *list = NULL;

    insert_head(&list, 30);
    insert_head(&list, 20);
    insert_head(&list, 10);
    insert_head(&list, 5);

    printf("原始: ");  print_list(list);   // 5 10 20 30

    delete_by_value(&list, 5);              // 删头节点
    printf("删5: ");  print_list(list);     // 10 20 30

    delete_by_value(&list, 20);             // 删中间
    printf("删20: "); print_list(list);     // 10 30

    delete_by_value(&list, 99);             // 找不到
    printf("删99: "); print_list(list);     // 10 30（不变）

    free_list(list);
    return 0;
}