// Binary search using recursion

#include <stdio.h>

#define MAX 20

int list[MAX];

int find(int element, int start, int end) {
	if (end < start || end == -1)
		return -1;
	int mid = (start + end) / 2;
	if (element == list[mid])
		return mid;
	if (element < list[mid])
		return find(element, start, mid - 1);
	return find(element, mid + 1, end);
}

int main() {
	char choice;
	int i=-1, a;
	printf("Please enter all elements in ascending order:\n");
	while(i < MAX) {
		printf("Enter another element? (y/n): ");
		scanf("%c", &choice);
		getchar();
		switch(choice) {
			case 'y':	printf("Enter element: ");
					scanf("%d", &list[++i]);
					getchar();
					break;
			case 'n':	printf("Enter element to find: ");
					scanf("%d", &a);
					getchar();
					a = find(a, 0, i);
					if (a == -1)
						printf("Element does not exist\n");
					else
						printf("Element found at %d\n", a);
					return 0;
			default:	printf("Invalid choice\n");
		}
	}
	printf("Enter element to find: ");
	scanf("%d", &a);
	a = find(a, 0, i);
	if (a == -1)
		printf("Element does not exist\n");
	else
		printf("Element found at %d\n", a);
	return 0;
}
