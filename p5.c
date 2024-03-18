#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
 if (top == MAX - 1) {
 printf("Stack overflow!\n");
 exit(1);
 }
 stack[++top] = value;
}
int pop() {
 if (top == -1) {
 printf("Stack underflow!\n");
 exit(1);
 }
 return stack[top--];
}
int evaluate(char* expression) {
 int i;
 for (i = 0; expression[i] != '\0'; i++) {
 if (isdigit(expression[i])) {
 push(expression[i] - '0');
 } else {
 int a = pop();
 int b = pop();
 int result;
 switch (expression[i]) {
 case '+':
 result = b + a;
 break;
 case '-':
 result = b - a;
 break;
 case '*':
 result = b * a;
 break;
 case '/':
 result = b / a;
 break;
 case '%':
 result = b % a;
 break;
 case '^':
 result = 1;
int j;
 for (j = 0; j < a; j++) {
 result *= b;
 }
 break;
 default:
 printf("Invalid operator: %c\n", expression[i]);
 exit(1);
 }
 push(result);
 }
 }
 return pop();
}
int main() {
 char expression[100]; // Allow space for a reasonable-sized expression
 printf("Enter the suffix expression: ");
 scanf("%s", expression);
 int result = evaluate(expression);
 printf("Result: %d\n", result);
 return 0;
}
