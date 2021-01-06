// Primitive stack operations

#include <stdio.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push() {
	if (top == SIZE - 1) {
		printf("Overflow\n");
	} else {
		printf("Enter element: ");
		scanf("%d", &stack[++top]);
	}
}

void pop() {
	if (top == -1) {
		printf("Underflow\n");
	} else {
		printf("Popped: %d\n", stack[top--]);
	}
}
void show() {
	if (top == -1) {
		printf("Empty\n");
	} else {
		for (int i = top; i >= 0; --i)
			printf("%d\n", stack[i]);
	}
}

int main() {
	int choice;
	while(1) {
		printf("\n1.Push\n2.Pop\n3.Show\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				push();
				break;
			case 2:
				pop();
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
