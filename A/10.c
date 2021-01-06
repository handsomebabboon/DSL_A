// Creation and display of binary search tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int element;
	struct node *left;
	struct node *right;
} node;

node *newNode(int element) {
	node *temp = (node *)malloc(sizeof(node));
	temp->element = element;
	return temp;
}

node *createBST(node *root, int e) {
	if (root == NULL) {
		root = newNode(e);
		root->left = NULL, root->right = NULL;
		return root;
	} else {
		if (root->element == e)
			printf("Duplicate element\n");
		else if (root->element > e)
			root->left = createBST(root->left, e);
		else
			root->right = createBST(root->right, e);
		return root;
	}
}

void inorder(node *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->element);
		inorder(root->right);
	}
}

void preorder(node *root) {
	if (root != NULL) {
		printf("%d ", root->element);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->element);
	}
}

int main() {
	int choice, a;
	node *root = NULL;
	while (1) {
		printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter element: ");
				scanf("%d", &a);
				root = createBST(root, a);
				break;
			case 2:
				inorder(root);
				printf("\n");
				break;
			case 3:
				preorder(root);
				printf("\n");
				break;
			case 4:
				postorder(root);
				printf("\n");
				break;
			case 5:
				return 0;
			default:
				printf("Undefined choice\n");
		}
	}
}
