/* This program is the implementation of complex number arithmetic
   operation. A complex number is represened as a
   pair of floating point numbers.
   Four operations of complex number addition, subtraction,
   multiplication, and division are defined as functions.
*/

#include <stdio.h>
#include "complex.h"

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

// Convert a floating-point (real) number to a complex number
complex r2c(float r) {
  complex c;
  
  c.re = r;
  c.im = 0.0;
  return c;
}

// Check the zerop of a complex number
int zerop(complex c) {
    
  return (c.re * c.re + c.im * c.im < 0.000001);
}

// Print a complex number
void printc(complex c) {
     
  if (c.im==0) printf("%6.4f", c.re);
  else if (c.re==0) printf("%6.4fi", c.im);
  else if (c.im>0) printf("%6.4f+%6.4fi", c.re, c.im);
  else printf("%6.4f%6.4fi", c.re, c.im);
}
