// Stack using Singly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int element;
	struct node *next;
} node;

node *top = NULL;

node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
		return NULL;
	int a;
	printf("Enter element: ");
	scanf("%d", &a);
	temp->element = a;
	temp->next = NULL;
	return temp;
}

int push(node *insert) {
	if (insert == NULL)
		return -1;
	insert->next = top;
	top = insert;
	return 0;
}
    
node *pop() {
	if (top != NULL) {
		node *temp = top;
		top = top->next;
		return temp;
	}
	return top;
}

int show() {
	if (top == NULL)
		return -1;
	node *temp = top;
	while(temp != NULL) {
		printf("%d\n", temp->element);
		temp = temp->next;
	}
	return 0;
}

int main() {
	int choice, a;
	node *temp;
	while(1) {
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:	a = push(newNode());
					if (a == -1)
						printf("Overflow\n");
					else
						printf("Success\n");
					break;
			case 2:	temp = pop();
					if (temp == NULL)
						printf("Underflow\n");
					else
						printf("Popped: %d\n", temp->element);
					break;
			case 3:	a = show();
					if (a == -1)
						printf("Empty\n");
					break;
			case 4:	return 0;
			default:	printf("Undefined choice\n");
		}
	}
}
