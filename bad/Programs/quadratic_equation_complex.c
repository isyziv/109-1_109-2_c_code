/* The program reads three coefficients a, b, and c of equation
   a*x*x+b*x+c=0. Compute the two roots r1 and r2 of this equation.
   Then replace the roots into the equation to verify your solution.
*/

#include <stdio.h>
#include <math.h>

typedef struct {
  float re;
  float im;
} complex;

// Complex number addition
complex add(complex x, complex y) {
  complex sum;
  
  sum.re = x.re + y.re;
  sum.im = x.im + y.im;
  return sum;
}

// Complex number substraction
complex subtract(complex x, complex y) {
  complex difference;
  
  difference.re = x.re - y.re;
  difference.im = x.im - y.im;
  return difference;
}

// Complex number multiplications
complex multiply(complex x, complex y) {
  complex product;
  
  product.re = x.re * y.re - x.im * y.im;
  product.im = x.re * y.im + x.im * y.re;
  return product;
}

// Complex number division
complex divide(complex x, complex y) {
  complex quotient;
  
  quotient.re = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im);
  quotient.im = (-x.re * y.im + x.im * y.re) / (y.re * y.re + y.im * y.im);
  return quotient;
}

// Print a complex number
void printc(complex c) {
     
  if (c.im==0) printf("%6.4f", c.re);
  else if (c.re==0) printf("%6.4fi", c.im);
  else if (c.im>0) printf("%6.4f+%6.4fi", c.re, c.im);
  else printf("%6.4f%6.4fi", c.re, c.im);
}

int main(void) {
  float a, b, c;
  float b_square_minus_4_a_c;
  float root1, root2;
  complex croot1, croot2;
 
  printf("�п�J�T�ӹ�ƫY�� a, b, and c: ");
  scanf("%f %f %f", &a, &b, &c);
  b_square_minus_4_a_c = b * b - 4 * a * c;
  if (b_square_minus_4_a_c >= 0) {
    root1 = (-b + sqrt(b_square_minus_4_a_c)) / (2 * a);
    root2 = (-b - sqrt(b_square_minus_4_a_c)) / (2 * a);
    printf("�@���G����{�� %6.4fX**2", a);
    if (b > 0) printf("+%6.4fX", b);
    else if (b < 0) printf("%6.4fX", b);
    if (c > 0) printf("+%6.4f", c);
    else if (c < 0) printf("%6.4f", c);
    printf("=0 ����ӹ�ڬO\n%6.4f �M %6.4f.\n\n", root1, root2);
  }
  else {
    croot1.re = -b / (2 * a);
    croot2.re = -b / (2 * a);
    croot1.im = sqrt(-b_square_minus_4_a_c) / (2 * a);
    croot2.im = -sqrt(-b_square_minus_4_a_c) / (2 * a);
    printf("�@���G����{�� %6.4fX**2", a);
    if (b > 0) printf("+%6.4fX", b);
    else if (b < 0) printf("%6.4fX", b);
    if (c > 0) printf("+%6.4f", c);
    else if (c < 0) printf("%6.4f", c);
    printf("=0 ����ӽƮڬO\n");
    printc(croot1);
    printf(" �M ");
    printc(croot2);
    printf(".\n\n");
  }
 
  system("pause");
  return 0;
}