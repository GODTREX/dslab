#include <stdio.h>
#include <stdlib.h>
struct Term {
 int coefficient;
 int x_exponent;
 int y_exponent;
 int z_exponent;
 struct Term * next;
};
void insertTerm(struct Term ** head, int coef, int x_exp, int y_exp, int z_exp) {
 struct Term * newTerm = (struct Term * ) malloc(sizeof(struct Term));
 newTerm -> coefficient = coef;
 newTerm -> x_exponent = x_exp;
 newTerm -> y_exponent = y_exp;
 newTerm -> z_exponent = z_exp;
 newTerm -> next = * head;
 * head = newTerm;
}
void addPolynomials(struct Term * poly1, struct Term * poly2, struct Term ** result) {
 while (poly1 != NULL && poly2 != NULL) {
 if (poly1 -> x_exponent == poly2 -> x_exponent && poly1 -> y_exponent == poly2 -> y_exponent && poly1 -> z_exponent == poly2 -> z_exponent) {
 int sum_coef = poly1 -> coefficient + poly2 -> coefficient;
 if (sum_coef != 0) {
 insertTerm(result, sum_coef, poly1 -> x_exponent, poly1 -> y_exponent, poly1 -> z_exponent);
 }
 poly1 = poly1 -> next;
 poly2 = poly2 -> next;
 } else if ((poly1 -> x_exponent + poly1 -> y_exponent + poly1 -> z_exponent) > (poly2 -> x_exponent + poly2 -> y_exponent + poly2 -> z_exponent)) {
 insertTerm(result, poly1 -> coefficient, poly1 -> x_exponent, poly1 -> y_exponent, poly1 -> z_exponent);
 poly1 = poly1 -> next;
 } else {
 insertTerm(result, poly2 -> coefficient, poly2 -> x_exponent, poly2 -> y_exponent, poly2 -> z_exponent);
 poly2 = poly2 -> next;
 }
 }
 while (poly1 != NULL) {
 insertTerm(result, poly1 -> coefficient, poly1 -> x_exponent, poly1 -> y_exponent, poly1 -> z_exponent);
 poly1 = poly1 -> next;
 }
 while (poly2 != NULL) {
 insertTerm(result, poly2 -> coefficient, poly2 -> x_exponent, poly2 -> y_exponent, poly2 -> z_exponent);
 poly2 = poly2 -> next;
 }
}
void displayPolynomial(struct Term * poly) {
 while (poly != NULL) {
 printf("%+dx^%dy^%dz^%d", poly -> coefficient, poly -> x_exponent, poly -> y_exponent, poly -> z_exponent);
 poly = poly -> next;
 }
 printf("\n");
}
int main() {
 struct Term * poly1 = NULL;
 struct Term * poly2 = NULL;
 struct Term * result = NULL;
 int numTerms1, numTerms2, i;
 printf("Enter the number of terms for POLY1: ");
 scanf("%d", & numTerms1);
 for (i = 0; i < numTerms1; i++) {
 int coef, x_exp, y_exp, z_exp;
 printf("Enter coefficient, x exponent, y exponent, and z exponent for term %d: ", i + 1);
 scanf("%d %d %d %d", & coef, & x_exp, & y_exp, & z_exp);
 insertTerm( & poly1, coef, x_exp, y_exp, z_exp);
 }
 printf("Enter the number of terms for POLY2: ");
 scanf("%d", & numTerms2);
 for (i = 0; i < numTerms2; i++) {
 int coef, x_exp, y_exp, z_exp;
 printf("Enter coefficient, x exponent, y exponent, and z exponent for term %d: ", i + 1);
 scanf("%d %d %d %d", & coef, & x_exp, & y_exp, & z_exp);
 insertTerm( & poly2, coef, x_exp, y_exp, z_exp);
 }
 printf("POLY1(x,y,z) = ");
 displayPolynomial(poly1);
 printf("POLY2(x,y,z) = ");
 displayPolynomial(poly2);
 addPolynomials(poly1, poly2, & result);
 printf("POLYSUM(x,y,z) = ");
 displayPolynomial(result);
 return 0;
}
