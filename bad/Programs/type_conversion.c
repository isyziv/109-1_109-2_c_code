/* This program illustrate implicit type conversion.
   Note that the result of variables g and h are
   different.
*/

#include <stdio.h>

int main(void) {
  int a = 10, b;
  float e = 10.50, f = 30.80, g, h;
  
  b = f / a;
  g = e - b;
  h = e - f / a;
  printf("b=%d, g=%4.2f, h=%4.2f\n", b, g, h);
  
  system("pause"); 
  return 0; 
}
