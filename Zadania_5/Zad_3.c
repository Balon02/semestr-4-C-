#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void remove_last(struct Node **head) {
    struct Node *current = *head;

    // Return if the list has less than two nodes
    if (current == NULL || current->next == NULL) {
        *head = NULL;
        free(current);
    }
    else {
        while (current->next->next != NULL)
            current = current->next;

        free(current->next);
        current->next = NULL;
    }
}

void push(struct Node **head, int new_data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void print(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printf("List before removing last element: ");
    print(head);
    printf("\n");

    remove_last(&head);

    printf("List after removing last element: ");
    print(head);
    printf("\n");

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}