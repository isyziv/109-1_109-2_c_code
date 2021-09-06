/* This program shows the output format of floating-point
   numbers. Specifier "%f" will output a floating-point nmuber
   using the fixed-point format, and "%E" (also, "%e") will
   output a floating-point number using the scientific noation
   format. 
*/ 
#include <stdio.h>

int main(void) {
  float r;

  r = 134.56789;
  printf("fixed-point format: %f\n", r);
  printf("floating-point format: %E\n", r);
  
  return 0;
}

