// Write a program to implement queue using a circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int element;
	struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
		return NULL;
	printf("Enter element: ");
	scanf("%d", &temp->element);
	temp->next = NULL;
	return temp;
}

int insert(node *in) {
	if (in == NULL)
		return -1;
	if (front == NULL) {
		front = in;
		in->next = in;
		rear = front;
		return 0;
	}
	in->next = rear->next;
	rear->next = in;
	rear = in;
	return 0;
}

int delete() {
	if (front == NULL)
		return -1;
	if (front->next == front) {
		front = NULL;
		rear = NULL;
		return 0;
	}
	rear->next = front->next;
	front = front->next;
	return 0;
}

int show() {
	if (front == NULL)
		return -1;
	printf("%d ", front->element);
	node *temp = front->next;
	while (temp != front) {
		printf("%d ", temp->element);
		temp = temp->next;
	}
	printf("\n");
	return 0;
}

int main() {
	int a, choice;
	while (1) {
		printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:	a = insert(newNode());
					if (a == -1)
						printf("Overflow\n");
					else
						printf("Success\n");
					break;
			case 2:	a = delete();
					if (a == -1)
						printf("Underflow\n");
					else
						printf("Success\n");
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
