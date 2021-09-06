#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rational.h"

int main(void) {
  rational a, b, c;
  int n, d;
  
  printf("Enter the numerator and denomiator of a: ");
  scanf("%d %d", &n, &d);
  a = ii2r(n, d);
  printf("Rational number a: ");
  printr(a);
  printf("\n\n");
  
  printf("Enter the numerator and denomiator of b: ");
  scanf("%d %d", &n, &d);
  b = ii2r(n, d);
  printf("Rational number b: ");
  printr(b);
  printf("\n\n");
  
  printf("Enter the numerator and denomiator of c: ");
  scanf("%d %d", &n, &d);
  c = ii2r(n, d);
  printf("Rational number c: ");
  printr(c);
  printf("\n\n");
  
  printf("a + b = ");
  printr(plus(a, b));
  printf("\n\n");
  
  printf("a - b = ");
  printr(minus(a, b));
  printf("\n\n");
  
  printf("a * b = ");
  printr(time(a, b));
  printf("\n\n");
  
  printf("a / b = ");
  printr(divide(a, b));
  printf("\n\n");
  
  printf("a * c + b / a = ");
  printr(plus(time(a, c), divide(b, a)));
  printf("\n\n");
  
  printf("a * (c - b) / (b + c * a) = ");
  printr(divide(time(a, minus(c, b)), plus(b, time(c, a))));
  printf("\n\n");
  
  system("pause");
  return 1;
}
