/* This program is to test the evaluation order to two operands
   of binary operation. Since the output value of c is 12, the
   evaluation is from left to right. 
*/ 

#include <stdio.h>

int main(void) {
  int a = 2;
  int b = 3; 
  int c;
  
  c = (++a) + a * b;
  printf("a: %d, b: %d, c: %d\n", a, b, c);
  
  system("pause"); 
  return 0; 
}
