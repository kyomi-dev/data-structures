#include <stdio.h>
#include <stdlib.h>
#include "stacks.h"

Stack* create(int size) {
    if (size <= 0) return NULL;

    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation for the stack failed.\n");
        return NULL;
    }

    stack->size = size;
    stack->top = -1;
    stack->items = (int*)malloc(size * sizeof(int));
    if (!stack->items) {
        printf("Memory allocation for the stack items failed.\n");
        free(stack);
        return NULL;
    }

    return stack;
}

inline bool push(int value, Stack* stack) {
    if (stack->top >= stack->size - 1) {
        printf("Stack is full\n");
        return false;
    }
    stack->items[++stack->top] = value;
    return true;
}

inline bool pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return false;
    }
    stack->top--;
    printf("Item removed.\n");
    return true;
}

inline int peek(const Stack* stack, size_t position) {
    if (position <= 0 || position > stack->top + 1) {
        printf("Position is invalid.\n");
        return -1;
    }
    int value = stack->items[stack->top - position + 1];
    printf("Position: %zu, Value: %d\n", position, value);
    return value;
}

inline bool isFull(const Stack* stack) {
    return stack->top >= stack->size - 1;
}

inline bool isEmpty(const Stack* stack) {
    if (stack->top <= -1) {
        printf("Stack is empty.\n");
        return true;
    }
    printf("Stack isn't empty.\n");
    return false;
}

inline bool display(const Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return false;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("Item: %d\n", stack->items[i]);
    }
    return true;
}

int main() {
    Stack* stack = create(7);
    if (!stack) {
        return 1;
    }

    int values[] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < 7; i++) {
        push(values[i], stack);
    }

    display(stack);
    pop(stack);
    display(stack);
    peek(stack, 2);

    free(stack->items);
    free(stack);

    return 0;
}
