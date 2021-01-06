// GCD using recursion

#include <stdio.h>

int GCD(int a, int b) {
	if(b != 0){
		return GCD(b, a % b);
	}
	return a;
}

int main() {
	int a, b;
	printf("Enter the two numbers\n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("GCD of %d and %d is %d\n", a, b, GCD(a, b));
	return 0;
}
