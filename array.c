#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array {
    int* a;
    int size;
    int length;
} Array;

void insert(Array* arr) {
    printf("Enter the length of the array: ");
    int length;
    scanf("%d", &length);
    arr->length = length;
    arr->a = (int*)malloc(sizeof(int) * length);

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
    tempArray = (int*)malloc(sizeof(int) * arr->length);
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

int lshift(Array* arr) {
    int firstElement = arr->a[0];

    for (int i = 0; i < arr->length - 1; i++) {
        arr->a[i] = arr->a[i + 1];
    }

    arr->a[arr->length - 1] = firstElement;

    return 0;
}

int rshift(Array* arr) {
    int lastElement = arr->a[arr->length - 1];

    for (int i = arr->length - 1; i > 0; i--) {
        arr->a[i] = arr->a[i - 1];
    }

    arr->a[0] = lastElement;

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

bool isSorted(Array* arr) {
    for (int i = 0; i < arr->length - 1; i++) {
        int previousElement = arr->a[i];
        int currentElement = arr->a[i + 1];
        if (previousElement > currentElement) {
            printf("Array is not sorted.\n");
            return false;
        }
    }
        printf("Array is sorted.\n");
        return true;
}

bool sort(Array* arr) {
    int length = arr->length;
    for (int i = 1; i < length; i++) {
        int key = arr->a[i];
        int j = i - 1;

        while (j >= 0 && arr->a[j] > key) {
            arr->a[j + 1] = arr->a[j];
            j = j - 1;
        }
        arr->a[j + 1] = key;
    }
    return true;
}

Array intersection(Array* arr1, Array* arr2) {
    Array intersection;
    intersection.a = (int*)malloc(sizeof(int) * (arr1->length + arr2->length));
    intersection.length = 0;

    for (int i = 0; i < arr1->length; i++) {
        for (int j = 0; j < arr2->length; j++) {
            if (arr1->a[i] == arr2->a[j]) {
                intersection.a[intersection.length++] = arr1->a[i];
                break;
            }
        }
    }
    return intersection;
}

Array difference(Array* arr1, Array* arr2) {
    Array difference;
    difference.a = (int*)malloc(sizeof(int) * (arr1->length));
    difference.length = 0;

    for (int i = 0; i < arr1->length; i++) {
        int found = 0;
        for (int j = 0; j < arr2->length; j++) {
            if (arr1->a[i] == arr2->a[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            difference.a[difference.length++] = arr1->a[i];
        }
    }

    return difference;
}


bool concat(Array* arr1, Array* arr2) {
    arr1->a = (int*)realloc(arr1->a, (arr1->length + arr2->length) * sizeof(int));

    for (int i = 0; i < arr2->length; i++) {
        arr1->a[arr1->length + i] = arr2->a[i];
    }

    arr1->length += arr2->length;
    return true;
}

int main() {
    Array arr1;
    Array arr2;

    insert(&arr1);
    sort(&arr1);
    display(&arr1);
    insert(&arr2);
    sort(&arr2);
    display(&arr2);
    Array intersectionArray = intersection(&arr1, &arr2);
    display(&intersectionArray);
    Array differenceArray = difference(&arr1, &arr2);
    printf("Difference below: \n");
    display(&differenceArray);
    free(intersectionArray.a);
    free(differenceArray.a);

    return 0;
}