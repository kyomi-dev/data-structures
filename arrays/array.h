typedef struct Array {
    int* a;
    int size;
    int length;
} Array;


void insert(Array* arr);

void display(Array* arr);

int find(Array* arr, int firstElement, int lastElement, int value);

void del(Array* arr);

int set(Array* arr, int value,  int index);

int reverse(Array* arr);

int lshift(Array* arr);

int rshift(Array* arr);

int max(Array* arr);

double avg(Array* arr);

bool isSorted(Array* arr);

bool sort(Array* arr);

Array intersection(Array* arr1, Array* arr2);

Array difference(Array* arr1, Array* arr2);

bool concat(Array* arr1, Array* arr2);

