// Reverse a given SLL

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
	getchar();
	temp->next = NULL;
	return temp;
}

int insert(node *insertNode) {
	if (insertNode == NULL) {
		return -1;
	} else if (front == NULL) {
		front = insertNode;
		rear = insertNode;
		return 0;
	} else {
		rear->next = insertNode;
		rear = insertNode;
		return 0;
	}
}

node *reverse(node *one, node *two) {
	if (two->next == NULL) {
		two->next = one;
		return one;
	}
	node *temp = reverse(two, two->next);
	temp->next = one;
	return one;
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
	char choice;
	int a;
	while(1) {
		printf("Enter an element to the list (y/n) : ");
		scanf("%c", &choice);
		getchar();
		switch(choice) {
			case 'y':	a = insert(newNode());
					if (a == -1)
						printf("Overflow\n");
					else	
						printf("Success\n");
					break;
			case 'n':	printf("Original list: ");
					a = show();
					if (a == -1) {
						printf("Empty\n");
						return 0;
					}
					reverse(NULL, front);
					front = rear;
					printf("Reversed list: ");
					a = show();
					if (a == -1)
						printf("Empty\n");
					return 0;
			default:	printf("Exiting\n");
					return 0;
		}
	}
}
