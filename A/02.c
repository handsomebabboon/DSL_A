//Primitive operations on Linear Queue using array

#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int front = 0;
int rear = -1;

void insert() {
	if (rear == SIZE - 1) {
		printf("Overflow\n");
	} else {
		printf("Enter the element: ");
		scanf("%d", &queue[++rear]);
	}
}

void delete() {
	if (rear < front) {
		printf("Underflow\n");
	} else {
		++front;
	}
}

void show() {
	if (rear < front) {
		printf("Empty\n");
	} else {
		for (int i=front; i <= rear; ++i) {
			printf("%d ", queue[i]);
		}
		printf("\n");
	}
}

int main() {
	int choice;
	while(1) {
		printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
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
				break;
			default:
				printf("Undefined choice\n");
		}
	}
}
