// Evaluation of postfix

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 50
int stack[SIZE];
int top = -1;

void push(int element) {
	if (top != SIZE - 1)
		stack[++top] = element;
	else
		printf("Overflow\n");
}
int pop() {
	if (top != -1)
		return stack[top--];
	else
		printf("Underflow\n");
}

int postfix_eval() {
	char temp[SIZE], ch;
	printf("Enter the postfix expression:\n");
	scanf("%s", temp);
	for(int i = 0, ch = temp[i]; ch != '\0'; ++i, ch = temp[i]) {
		if (isdigit(ch)) {
			push(ch - '0');
		} else {
			int op2 = pop();
			int op1 = pop();
			switch(ch) {
				case '+':
					push(op1 + op2);
					break;
				case '-':
					push(op1 - op2);
					break;
				case '*':
					push(op1 * op2);
					break;
				case '/':
					push(op1 / op2);
					break;
				case '^':
					push(pow(op1, op2));
					break;
			}
		}
	}	
}

int main() {
	postfix_eval();
	printf("%d\n", stack[0]);
	return 0;
}
