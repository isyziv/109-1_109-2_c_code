#include <stdio.h>

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
  quotient.im = (x.re * y.im - x.im * y.re) / (y.re * y.re + y.im * y.im);
  return quotient;
}

complex r2c(float x) {
  complex c;
  
  c.re = x;
  c.im = 0.0;
  return c;
}

int equal0(complex c) {

  return (c.re * c.re + c.im * c.im < 0.00000001);
}

complex quadratic_eval(float c2, float c1, float c0, complex para) {
  complex result;
  
  result = multiply(r2c(c2), multiply(para, para));
  result = add(result, multiply(r2c(c1), para));
  result = add(result, r2c(c0));
  return result;
}

int main(void) {

  float c2, c1, c0;
  complex root1, root2;
  
  printf("\n");
  printf("Enter coefficient c2: ");
  scanf("%f", &c2);
  printf("Enter coefficient c1: ");
  scanf("%f", &c1);
  printf("Enter coefficient c0: ");
  scanf("%f", &c0);
  printf("Enter the first root: ");
  scanf("%f %f", &root1.re, &root1.im);
  printf("Enter the second root: ");
  scanf("%f %f", &root2.re, &root2.im);
  printf("\n");
  
  if (equal0(quadratic_eval(c2, c1, c0, root1)) &&
      equal0(quadratic_eval(c2, c1, c0, root2))) {
    printf("%6.4f+%6.4fi and %6.4f+%6.4fi are the roots of equation %6.4fx**2+%6.4fx+%6.4f=0.",
           root1.re, root1.im, root2.re, root2.im, c2, c1, c0);
  }
  else {
    printf("%6.4f+%6.4fi and %6.4f+%6.4fi are not the roots of equation %6.4fx**2+%6.4fx+%6.4f=0.",
           root1.re, root1.im, root2.re, root2.im, c2, c1, c0);
  }
  
  exit(1);
}
