/* The program reads three coefficients a, b, and c of equation
   a*x*x+b*x+c=0. If b*b-4ac is greater than or equal to zeor,
   the real roots of the equation is computed and printed;
   otherwise, the complex roots of the equation is computed and printed;
*/

#include <stdio.h>
#include <math.h>
#include "complex.h"

int main(void) {
  float a, b, c;
  complex root1, root2;
  float square;
 
  printf("Solving the two roots of equation a*x*x+b*x+c=0.\n");
  printf("Please enter three coefficients a, b, and c: ");
  scanf("%f %f %f", &a, &b, &c);
  
  square = b * b - 4 * a * c;
  if (square >= 0) {
    root1.re = (-b + sqrt(square)) / (2 * a);
    root1.im = 0.0;
    root2.re = (-b - sqrt(square)) / (2 * a);
    root2.im = 0.0;
  }
  else {
    root1.re = -b / (2 * a);
    root1.im = sqrt(-square) / (2 * a);
    root2.re = -b / (2 * a);
    root2.im = -sqrt(-square) / (2 * a);
  }
  
  if (zerop(add(add(multiply(r2c(a), multiply(root1, root1)),
                    multiply(r2c(b), root1)),
                r2c(c))) &&
      zerop(add(add(multiply(r2c(a), multiply(root2, root2)),
                    multiply(r2c(b), root2)),
                r2c(c)))) {
    printf("\n");
    printc(root1);
    printf(" and ");
    printc(root2);
    printf(" are the valid roots.\n\n");
  }
  else {
    printf("\n");
    printc(root1);
    printf(" and ");
    printc(root2);
    printf(" are not the valid roots.\n\n");
  }
 
  system("pause");
  return 0;
}
