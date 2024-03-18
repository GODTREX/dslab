#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX], revstack[MAX], top = -1;
void push();
void pop();
void palindrome();
void display();
int main() {
 int choice;
 while (1) {
 printf("_____________MENU______________\n");
 printf("1.PUSH\n");
 printf("2.POP\n");
 printf("3.PALINDROME\n");
 printf("4.DISPLAY\n");
 printf("5.EXIT\n");
 printf("Enter Your Choice : ");
 scanf("%d", & choice);
 switch (choice) {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 case 3:
 palindrome();
 break;
 case 4:
 display();
 break;
 case 5:
 exit(0);
 break;
 default:
 printf("INVALID CHOICE\n");
 break;
 }
 }
}
void push() {
 int ele;
 if (top == MAX - 1) {
 printf("Stack Overflow\n");
 } else {
 printf("Enter the element to be inserted: ");
 scanf("%d", & ele);
 top = top + 1;
 stack[top] = ele;
 }
}
void pop() {
 int ele;
 if (top == -1) {
 printf("Stack underflow\n");
 } else {
 ele = stack[top];
 top = top - 1;
 printf("The popped out element is %d\n", ele);
 }
}
void palindrome() {
 int i, j;
 for (i = 0; i <= top; i++) {
 revstack[i] = stack[top - i];
 }
 display();
 printf("\nThe reversed elements of the stack are: ");
 for (i = 0; i <= top; i++) {
 printf("%d\t", revstack[i]);
 }
 j = 0;
 while (stack[j] == revstack[j] && (j <= top)) {
 j++;
 }
 if (j > top) {
 printf("\nThe elements in the stack form a palindrome\n");
 } else {
 printf("\nThe elements in the stack do not form a palindrome\n");
 }
}
void display() {
 int i;
 if (top == -1) {
 printf("\nStack is empty\n");
 } else {
 printf("\nThe elements of the stack are:\t");
 for (i = top; i >= 0; i--) {
 printf("%d\t", stack[i]);
 }
 printf("\n");
 }
}
