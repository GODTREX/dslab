#include <stdio.h>
#include <stdlib.h>
int * ht, n, m;
int count = 0;
void insert(int k) {
 int currentIndex = k % m;
 while (ht[currentIndex] != -1) {
 currentIndex = (currentIndex + 1) % m;
 }
 ht[currentIndex] = k;
 count++;
}
void display() {
 int i;
 if (count == 0) {
 printf("\nHash Table is empty");
 return;
 }
 printf("\nHash Table contents are:\n ");
 for (i = 0; i < m; i++)
 printf("\n T[%d] --> %d ", i, ht[i]);
}
int main() {
 int i;
 printf("\nEnter the number of employee records (N): ");
 scanf("%d", & n);
 printf("\nEnter the two-digit memory locations (m) for the hash table: ");
 scanf("%d", & m);
 ht = (int * ) malloc(m * sizeof(int));
 for (i = 0; i < m; i++)
 ht[i] = -1;
 printf("\nEnter the four-digit key values (K) for N Employee Records:\n");
 for (i = 0; i < n; i++) {
 int k;
 scanf("%d", & k);
 if (count == m) {
 printf("\n~~~Hash table is full. Cannot insert the record %d key~~~", i + 1);
 break;
 }
 insert(k);
 }
 display();
 return 0;
}
