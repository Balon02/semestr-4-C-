#include<stdio.h>

typedef struct list_el {
    int data;
    struct list_el *next;
} PslistEl;

void add_first(PslistEl **head, int v) {
    PslistEl *new_el;
    new_el = (PslistEl*) malloc(sizeof(PslistEl));
    new_el->data = v;
    new_el->next = *head;
    *head = new_el;
}

int main() {
    PslistEl *head = NULL;
    add_first(&head, 5);
    add_first(&head, 3);
    add_first(&head, 1);
    PslistEl *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}