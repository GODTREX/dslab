#include<stdio.h>
void tower(int, char, char, char);
void main() {
 int n;
 printf("\n Enter the number of disks : ");
 scanf("%d", & n);
 printf("The sequence of move in Tower of Hanoi are\n");
 tower(n, 'A', 'B', 'C');
}
void tower(int n, char source, char auxiliary, char destination) {
 if (n == 1) {
 printf("Move disk 1 from %c to %c \n", source, destination);
 return;
 }
 tower(n - 1, source, destination, auxiliary);
 printf("Move disk %d from %c to %c \n", n, source, destination);
 tower(n - 1, auxiliary, source, destination);
}
