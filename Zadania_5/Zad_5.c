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

Node *remove_by_value(Node *head, int value)
{
    if (head == NULL)
    {
        printf("Error: list is empty.\n");
        return head;
    }

    Node *current = head;
    Node *previous = NULL;

    if (head->data == value)
    {
        head = current->next;
        free(current);
        return head;
    }

    while (current->data != value)
    {
        if (current->next == NULL)
        {
            printf("Error: value is not in list.\n");
            return head;
        }

        previous = current;
        current = current->next;
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

    printf("List before removing by value: ");
    print_list(head);

    head = remove_by_value(head, 3);

    printf("List after removing by Value: ");
    print_list(head);

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}