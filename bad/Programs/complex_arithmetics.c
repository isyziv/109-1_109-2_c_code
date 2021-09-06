// This program represents a complex number as a
// pair of floating point numbers.
// Four operations of complex numbers: addition, subtraction,
// multiplication, and division are defined as functions.

#include <stdio.h>

// Define a new data type of complex numbers.
// A complex number is represented as a pair of two
// floating point numbers, one for the real part and 
// another for the imaginary part.
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

  complex a, b;
  complex ans;
  
  printf("Enter two numbers for complex number a: ");
  scanf("%f %f", &a.re, &a.im);
  printf("    a = ");
  printc(a);
  printf("\n\n");
  
  printf("Enter two numbers for complex number b: ");
  scanf("%f %f", &b.re, &b.im);
  printf("    b = ");
  printc(b);
  printf("\n\n");
  
  ans = add(a, b);
  printf("    ans = ");
  printc(ans);
  printf("\n\n");
  
  ans = subtract(a, b);
  printf("    ans = ");
  printc(ans);
  printf("\n\n");
  
  ans = multiply(a, b);
  printf("    ans = ");
  printc(ans);
  printf("\n\n");
  
  ans = divide(a, b);
  printf("    ans = ");
  printc(ans);
  printf("\n\n");
  
  system("pause");
  return 0;
}
