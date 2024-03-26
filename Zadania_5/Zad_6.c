#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *insertAtIndex(Node* head, int pos, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Update position if the new position is 1
    if (pos == 1) {
        newNode->data = data;
        newNode->next = head;
        return newNode;
    }

    Node* current = head;

    for (int i = 1; i < pos - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL) {
        printf("Position out of range. Cannot insert at position %d.\n", pos);
        free(newNode);
        return head;
    }

    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void printList(Node* head) {
    Node* current = head;
    printf("List: ");

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    head = insertAtIndex(head, 1, 10);
    head = insertAtIndex(head, 1, 20);
    head = insertAtIndex(head, 1, 30);
    printList(head);

    head = insertAtIndex(head, 2, 5);
    printList(head);

    head = insertAtIndex(head, 5, 40);
    printList(head);

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}