#ifndef STACKS_H
#define STACKS_H

#include <stdbool.h>

typedef struct {
    int size;
    int top;
    int* items;
} Stack;

Stack* create(int size);
bool push(int value, Stack* stack);
bool pop(Stack* stack);
int peek(const Stack* stack, size_t position);
bool isFull(const Stack* stack);
bool isEmpty(const Stack* stack);
bool display(const Stack* stack);

#endif
