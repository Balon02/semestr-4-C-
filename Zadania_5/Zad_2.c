#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int pop(Node **head) {
    if (*head == NULL) {
        printf("Error: Stack is empty.\n");
        return -1;
    }

    int popped_data = (*head)->data;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);

    return popped_data;
}

int main() {
    Node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    printf("Popped data: %d\n", pop(&head));
    printf("Popped data: %d\n", pop(&head));
    printf("Popped data: %d\n", pop(&head));

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}