// Write a program to implement stack using a circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int element;
	struct node *next;
} node;

node *top = NULL;

node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
		return NULL;
	printf("Enter element: ");
	scanf("%d", &temp->element);
	temp->next = NULL;
	return temp;
}

int push(node *in) {
	if (in == NULL)
		return -1;
	if (top == NULL) {
		top = in;
		in->next = in;
		return 0;
	}
	node *temp = top;
	while(temp->next != top)
		temp = temp->next;
	temp->next = in;
	in->next = top;
	top = in;
	return 0;
}

node *pop() {
	if (top == NULL)
		return NULL;
	node *temp = top;
	if (top->next == top) {
		top = NULL;
		return temp;
	}
	node *temp2 = top;
	while (temp2->next != top)
		temp2 = temp2->next;
	temp2->next = top->next;
	top = top->next;
	return temp;
}

int show() {
	if (top == NULL)
		return -1;
	printf("%d\n", top->element);
	node *temp = top->next;
	while (temp != top) {
		printf("%d\n", temp->element);
		temp = temp->next;
	}
	return 0;
}

int main() {
	int a, choice;
	node *b;
	while (1) {
		printf("\n1.Push\n2.Pop\n3.Show\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:	a = push(newNode());
					if (a == -1)
						printf("Overflow\n");
					else
						printf("Success\n");
					break;
			case 2:	b = pop();
					if (b == NULL)
						printf("Underflow\n");
					else
						printf("Popped: %d\n", b->element);
					break;
			case 3:	a = show();
					if (a == -1)
						printf("Empty\n");
					break;
			case 4:	printf("Exiting\n");
					return 0;
			default:	printf("Undefined choice\n");
		}
	}
}
