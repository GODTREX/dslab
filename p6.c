#include<stdio.h>
#include<stdlib.h>
#define max 4
int q[10], front = 0, rear = -1;
void insert();
void delete();
void display();
int main() {
 int choice;
 printf("\n Circular Queue\n");
 printf("1.Insert\n2.Delete\n3.Display\n4.Exit");
 do {
 printf("\nEnter your choice : ");
 scanf("%d", & choice);
 switch (choice) {
 case 1:
 insert();
 break;
 case 2:
 delete();
 break;
 case 3:
 display();
 break;
 }
 }
 while (choice != 4);
}
void insert() {
 int ele;
 if ((front == 0 && rear == max - 1) || (front > 0 && rear == front - 1)) {
 printf("Queue Overflow\n");
 return;
 } else {
 printf("Enter element to be inserted :");
 scanf("%d", & ele);
 if (rear == max - 1)
 rear = -1;
 q[++rear] = ele;
 }
}
void delete() {
 int ele;
 if ((front == 0) && (rear == -1)) {
 printf("Queue Underflow");
 return;
 }
 if (front == rear) {
 ele = q[front];
 rear = -1;
 front = 0;
 } else
 if (front == max - 1) {
 ele = q[front];
 front = 0;
 } else
 ele = q[front++];
 printf("Deleted element is %d\n", ele);
}
void display() {
 int i, j;
 if (front == 0 && rear == -1) {
 printf("Queue Underflow\n");
 return;
 }
 if (front > rear) {
 for (i = front; i < max; i++)
 printf("%d", q[i]);
 for (i = 0; i <= rear; i++)
 printf("%d\t", q[i]);
 printf("\n Rear is at %d\n", q[rear]);
 printf("\n Front is at %d\n", q[front]);
 } else {
 for (i = front; i <= rear; i++) {
 printf("%d\t", q[i]);
 }
 printf("\nRear is at %d\n", q[rear]);
 printf("Front is at %d\n", q[front]);
 }
}
