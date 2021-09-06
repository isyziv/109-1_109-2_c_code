#include <stdio.h>
#include <stdlib.h>

int main(void) {

  float a, b, c, r1, r2;
  
  printf("Enter coefficient a: ");
  scanf("%f", &a);
  printf("Enter coefficient b: ");
  scanf("%f", &b);
  printf("Enter coefficient c: ");
  scanf("%f", &c);
  printf("Enter the first root: ");
  scanf("%f", &r1);
  printf("Enter the second root: ");
  scanf("%f", &r2);
  printf("\n");
  
  if (a*r1*r1+b*r1+c==0 && a*r2*r2+b*r2+c==0) {
    printf("%6.4f and %6.4f are the roots of equation %6.4f x**2 + %6.4f x + %6.4f = 0.\n\n",
           r1, r2, a, b, c);
  }
  else {
    printf("%6.4f and %6.4f are not the roots of equation %6.4f x**2 + %6.4f x + %6.4f = 0.\n\n",
           r1, r2, a, b, c);
  }
  
  system("pause");
  return 0;
}
