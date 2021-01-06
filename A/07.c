// Queue using Singly linked list

#include<stdio.h>
#include<stdlib.h>

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
	int a;
	printf("Enter element: ");
	scanf("%d", &a);
	temp->element = a;
	temp->next = NULL;
	return temp;
}

int insert(node *in) {
	if (in == NULL)
		return -1;
	if (front == NULL) {
		front = in, rear = in;
		return 0;
	}
	rear->next = in;
	rear = in;
	return 0;
}

int delete() {
	if (front != NULL) {
		front = front->next;
		return 0;
	}
	return -1;
}

int show() {
	if (front == NULL)
		return -1;
	node *temp = front;
	while(temp != NULL) {
		printf("%d ", temp->element);
		temp = temp->next;
	}
	printf("\n");
	return 0;
}

int main() {
	int choice, a;
	while(1) {
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
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
						printf("Deleted\n");
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
