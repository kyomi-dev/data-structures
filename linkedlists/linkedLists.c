#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedLists.h"

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

bool del(Node** head, size_t position) {
	Node* current = *head;
    Node* previous = NULL;

    if (*head == NULL) {
        return false;
    }


    if (position == 1) {
        *head = current->next;
        free(current);
        return true;
    }

    for (size_t i = 1; i < position; i++) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    free(current);
    return true;
}

bool concatenate(Node** firstHead, Node** secondHead) {
    Node* current = *firstHead;

    if (*firstHead == NULL) {
        *firstHead = *secondHead;
        return true;
    }

    while (current->next != NULL) {
        current = current->next;

        if (current->next == NULL) {
            current->next = *secondHead;
            break;
        }
    }
    
    return true;
}



int main() {
    Node* head = create(5);
    insert(&head, 10, 2);
    insert(&head, 52, 3);
    insert(&head, -9, 4);
    insert(&head, 90, 5);
    insert(&head, -6, 6);

    Node* head2 = create(200);
    insert(&head2, 300, 2);
    insert(&head2, 400, 3);
    insert(&head2, 500, 4);
    insert(&head2, 600, 5);
    insert(&head2, 700, 6);
    concatenate(&head, &head2);
	printf("The list is: \n");
	display(head);
	del(&head, 3);
	printf("\nThe list after deletion is: \n");
	display(head);
    return 0;
}
