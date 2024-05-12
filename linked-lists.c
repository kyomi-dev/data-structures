#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Node {
	void* data;
	struct Node* next;
} Node;

int main() {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("What would be the value in your linked list?\n");
	printf("\t 1. An integer\n");
	printf("\t 2. A float\n");
	printf("\t 3. A double\n");
	printf("\t 4. A char\n");
	int option;
	scanf("%d", &option);

	switch(option) {
		case 1:
			printf("Enter an integer: \n");
			int value;
			scanf("%d", &value);
			p->data = malloc(sizeof(int));
			*(int*)(p->data) = value;
			p->next = NULL;

			printf("Node data: %d\nNode next: %s\n", *(int*)p->data, p->next);
			break;

		case 2:
			printf("Enter a float: \n");
			float float_value;
			scanf("%f", &float_value);
			p->data = malloc(sizeof(float));
			*(float*)(p->data) = float_value;
			p->next = NULL;

			printf("Node data: %.2f\nNode next: %s\n", *(float*)p->data, p->next);
			break;


		case 3:
			printf("Enter a double: ");
			double double_value;
			scanf("%lf", &double_value);
			p->data = malloc(sizeof(double));
			*(double*)(p->data) = double_value;
			p->next = NULL;

			printf("\nNode data: %.2lf\nNode next: %s\n", *(double*)p->data, p->next);
			break;

		case 4:
			printf("Enter a char: ");
			char char_value;
			scanf(" %c", &char_value);
			p->data = malloc(sizeof(char));
			*(char*)(p->data) = char_value;
			p->next = NULL;

			printf("\nNode data: %c\nNode next: %s\n", *(char*)p->data, p->next);
			break;

		default:
			return 1;
	}

	free(p->data);
	free(p);
	return 0;
}
