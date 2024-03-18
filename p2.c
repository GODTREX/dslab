#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[100], pat[100], rep[100], res[100];
int flag;
void read();
void search();
void replace(int stpos, int endpos);
int main() {
 int i;
 read();
 strcpy(res, str);
 search();
 return 0;
}
void read() {
 printf("Enter the main string:");
 scanf("%s", str);
 printf("Enter the pattern string:");
 scanf("%s", pat);
 printf("Enter the replace string:");
 scanf("%s", rep);
}
void search() {
 int i;
 for (i = 0; str[i] != '\0'; i++) {
 int j = 0;
 int k = i;
 while (str[k] == pat[j] && pat[j] != '\0') {
 k++;
 j++;
 }
 if (pat[j] == '\0') {
 printf("String found at position %d in", i);
 replace(i, k);
 flag = 1;
 }
 }
 if (!flag) {
 printf("Pattern not found : ");
 }
}
void replace(int stpos, int endpos) {
 int i, j, k = 0;
 for (j = stpos; j < endpos; j++) {
 res[j] = rep[k];
 k++;
 }
 printf("The new string is %s", res);
}
