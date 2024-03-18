#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
char stack[MAX], infix[MAX], postfix[MAX];
int pos = 0, top = -1;
void convert();
int pree(char symb);
void push(char ele);
char pop();
int main() {
 printf("Enter infix expression :");
 scanf("%s", infix);
 convert();
 printf("Equvalent postfix expression : ");
 puts(postfix);
}
void convert() {
 int i = 0;
 char symb, ele;
 while (infix[i] != '\0') {
 symb = infix[i++];
 if (symb == '(')
 push(symb);
 else if (symb == ')') {
 while (stack[top] != '(') {
 postfix[pos++] = pop();
 }
 ele = pop();
 } else if (isalnum(symb)) {
 postfix[pos++] = symb;
 } else {
 while (top != -1 && pree(stack[top]) >= pree(symb)) {
 postfix[pos++] = pop();
 }
 push(symb);
 }
 }
 while (top != -1) {
 postfix[pos++] = pop();
 }
 postfix[pos] = '\0';
}
int pree(char symb) {
 switch (symb) {
 case '^':
 return (5);
 case '%':
 case '*':
 case '/':
 return (4);
 case '+':
 case '-':
 return (3);
 case '(':
 case ')':
 return (2);
 default:
 return (1);
 }
}
void push(char ele) {
 if (top == MAX - 1) {
 printf("Stack overflow\n");
 exit(1);
 } else {
 top++;
 stack[top] = ele;
 }
}
char pop() {
 char ele;
 if (top == -1) {
 printf("Stack underflow\n");
 exit(1);
 } else {
 ele = stack[top];
 top--;
 }
 return ele;
}
