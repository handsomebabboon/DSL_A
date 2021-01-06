// Tower of hanoi using recursion

#include <stdio.h>

void hanoi(int n, char from, char to, char temp) {
	if (n == 1) {
		printf("Move disk 1 from rod %c to rod %c\n", from, to);
		return;
	}
	hanoi(n-1, from, temp, to);
	printf("Move disk %d from rod %c to rod %c\n", n, from, to);
	hanoi(n-1, temp, to, from);
}
 
int main() {
	int n;
	printf("Enter number of disks: ");
	scanf("%d", &n);
	hanoi(n, 'A', 'C', 'B');
	return 0;
}


