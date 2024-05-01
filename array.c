#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array {
    int* a;
    int size;
    int length;
} Array;

void insert(Array* arr) {
    printf("Enter the numbers, separated by a space: ");
    for (int i = 0; i < arr->length; i++) {
        scanf("%d", &arr->a[i]);
    }
    printf("\n");
}

void display(Array* arr) {
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->a[i]);
    }
    printf("\n");
}

int find(Array* arr, int firstElement, int lastElement, int value) {
    int mid = (firstElement + lastElement) / 2;

    if (firstElement > lastElement) return -1;
    if (arr->a[mid] == value) {
        printf("Element found at index: %d\n", mid);
        return mid;
    }

    else if(arr->a[mid] < value) return find(arr, mid + 1, lastElement, value);
    else {
        return find(arr, firstElement, mid - 1, value);
    }
}


int main() {
    Array arr;

    printf("Enter the array length: ");
    scanf("%d", &arr.length);

    arr.size = arr.length * sizeof(int);

    arr.a = (int*)malloc(sizeof(int) * arr.length);

    insert(&arr);
    display(&arr);
    free(arr.a);

    return 0;
}
