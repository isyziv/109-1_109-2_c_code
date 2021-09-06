/* The program reads three coefficients a, b, and c of equation
   a*x*x+b*x+c=0. If b*b-4ac is greater than or equal to zeor,
   the real roots of the equation is computed and printed;
   otherwise, it outputs a message of no real roots.
*/

#include <stdio.h>
#include <math.h>

int main(void) {
  float a, b, c;
  float root1, root2;
  float b_square_minus_4_a_c;
 
  printf("Solving real roots of equation a*X**2+b*X+c = 0.\n");
  printf("Please enter three coefficients a, b, and c: ");
  scanf("%f %f %f", &a, &b, &c);
  b_square_minus_4_a_c = b * b - 4 * a * c;
  if (b_square_minus_4_a_c >= 0) {
    root1 = (-b + sqrt(b_square_minus_4_a_c)) / (2 * a);
    root2 = (-b - sqrt(b_square_minus_4_a_c)) / (2 * a);
    printf("The real roots of equation %4.2fX**2", a);
    if (b > 0) printf("+%4.2fX", b);
    else if (b < 0) printf("%4.2fX", b);
    if (c > 0) printf("+%4.2f", c);
    else if (c < 0) printf("%4.2f", c);
    printf("=0 are %4.2f and %4.2f.\n\n", root1, root2);
  }
  else {
    printf("Equation %4.2fX**2", a);
    if (b > 0) printf("+%4.2fX", b);
    else if (b < 0) printf("%4.2fX", b);
    if (c > 0) printf("+%4.2f", c);
    else if (c < 0) printf("%4.2f", c);
    printf("=0 has no real roots.\n\n");
  }
 
  system("pause");
  return 0;
}
