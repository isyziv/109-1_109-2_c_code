/* This program will output a variable without casting
   using format specifiers of other data types. Unexpedted
   results may happer, if an improper specifier is used. 
*/ 

#include <stdio.h>

int main(void) {
  char c;
  int i;
  float r;

  c = 'A';
  printf("Character as integer: %d\n", c);
  printf("Character as floating-point: %E\n", c);
  i = 49;
  printf("Integer as character: %c, %X\n", i, i);
  printf("Integer as floating-point: %E\n", i);
  r = 97.512;
  printf("Floating-point as character: %c, %X\n", r, r);
  printf("Floating-point as integer: %d\n", r);
  
  return 0;
}

