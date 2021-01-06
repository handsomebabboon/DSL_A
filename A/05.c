// Write a program to implement the operations of a circular queue

#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int front = 0;
int elements = 0;

void insert() {
	if (elements == SIZE - 1) {
		printf("Overflow\n");
	} else {
		printf("Enter the element: ");
		scanf("%d", &queue[(front + elements) % SIZE]);
		++elements;
	}
}

void delete() {
	if (elements == 0) {
		printf("Underflow\n");
	} else {
		++front, --elements;
	}
}

void show() {
	if (elements == 0) {
		printf("Empty\n");
	} else {
		for(int i=0; i < elements; ++i)
			printf("%d ", queue[(front + i) % SIZE]);
		printf("\n");
	}
}

int main() {
	int selection;
	while(1) {
		printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit\nEnter selection: ");
		scanf("%d", &selection);
		switch(selection) {
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				show();
				break;
			case 4:
				return 0;
			default:
				printf("Undefined choice\n");
		}
	}
}
