#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *list_add(Node *head, int data)
{
    Node *current = (Node *) malloc(sizeof(Node));
    current->data = data;
    current->next = head;
    return current;
}

Node *remove_by_index(Node *head, int index)
{
    if (head == NULL)
    {
        printf("Error: list is empty.\n");
        return head;
    }

    Node *current = head;
    Node *previous = NULL;

    if (index == 0)
    {
        head = current->next;
        free(current);
        return head;
    }

    while (index > 0)
    {
        if (current->next == NULL)
        {
            printf("Error: index is out of range.\n");
            return head;
        }

        previous = current;
        current = current->next;
        index--;
    }

    previous->next = current->next;
    free(current);

    return head;
}

void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;

    head = list_add(head, 1);
    head = list_add(head, 2);
    head = list_add(head, 3);
    head = list_add(head, 4);
    head = list_add(head, 5);

    printf("List before removing by index: ");
    print_list(head);
    printf("Index: 0 -> ");

    head = remove_by_index(head, 0);

    printf("List after removing by index: ");
    print_list(head);

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}