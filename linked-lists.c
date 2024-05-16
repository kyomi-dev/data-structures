#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void display(Node* node) {
    while (node != NULL) {
        printf("Value: %d\n", node->data);
        node = node->next;
    }
}

Node* create(int value) {
    Node* createdNode = (Node*)malloc(sizeof(Node));
    createdNode->data = value;
    createdNode->next = NULL;
    return createdNode;
}

bool insert(Node** head, int value, size_t position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return true;
    }

    Node* current = *head;
    for (size_t i = 1; i < position - 1; i++) {
        if (current == NULL) {
            free(newNode);
            return false;
        }
        current = current->next;
    }

    if (current == NULL) {
        free(newNode);
        return false;
    }

    newNode->next = current->next;
    current->next = newNode;

    return true;
}

int main() {
    Node* head = create(5);
    display(head);
    printf("\n");

    insert(&head, 10, 2);
    insert(&head, 52, 3);
    insert(&head, -9, 4);
    insert(&head, 90, 5);
    insert(&head, -6, 6);

    display(head);
    return 0;
}
