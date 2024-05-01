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

void del(Array* arr) {
    int element;
    printf("Enter the element you want to remove: ");
    scanf("%d", &element);

    int index = find(arr, 0, arr->length - 1, element);

    if (index != -1) {
        for (int i = index; i < arr->length - 1; i++) {
            arr->a[i] = arr->a[i + 1];
        }
        arr->length--;
        printf("Element %d removed successfully.\n", element);
    } else {
        printf("Element not found in the array.\n");
    }
}

int set(Array* arr, int value,  int index){
    if (index >= 0 && index <= arr->length - 1) {
        arr->a[index] = value;
        return 0;
    }
    else {
        printf("Array has length of = %d but you're trying to access index %d\n", arr->length, index);
        return -1;
    }
}

int reverse(Array* arr) {
    int* tempArray;
    tempArray = (int*)malloc(arr->size);
    if (tempArray == NULL) {
        return -1;
    }

    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        tempArray[j] = arr->a[i];
    }

    for (int i = 0; i < arr->length; i++) {
        arr->a[i] = tempArray[i];
    }

    free(tempArray);
    return 0;
}


int max(Array* arr) {
    int maxValue = 0;

    for (int i = 0; i < arr->length - 2; i++) {
        if (arr->a[i] > arr->a[i + 1]) {
            maxValue = arr->a[i];
        } else {
            maxValue = arr->a[i + 1];
        }
    }
    printf("Maximum value is: %d\n", maxValue);
    return maxValue;
}

double avg(Array* arr) {
    int sum = 0;
    
    for (int i = 0; i < arr->length; i++) {
        sum += arr->a[i];
    }

    double average = (double)sum / arr->length; 
    printf("Average value is: %.2lf\n", average);
    return average;
}



void swap(int firstNumber, int secondNumber) {
    int temp;
    temp = firstNumber;
    firstNumber = secondNumber;
    temp = secondNumber;
}

int main() {
    Array arr;

    printf("Enter the array length: ");
    scanf("%d", &arr.length);

    arr.size = arr.length * sizeof(int);

    arr.a = (int*)malloc(sizeof(int) * arr.length);

    insert(&arr);
    display(&arr);
    del(&arr);
    display(&arr);

    int element;
    printf("Enter the element you want to find: ");
    scanf("%d", &element);

    find(&arr, 0, arr.length - 1, element);
    set(&arr, 40, 3);
    display(&arr);
    max(&arr);
    avg(&arr);
    reverse(&arr);
    display(&arr);
    free(arr.a);

    return 0;
}
