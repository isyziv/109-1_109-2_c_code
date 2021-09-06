/* This program will output a variable with casting
   using format specifiers of other data types. All
   output results are correct. 
*/

#include <stdio.h>

int main(void) {
  char c;
  int i;
  float r;

  c = 'A';
  printf("Character as integer: %d\n", c);
  printf("Character as floating-point: %E\n", (float) c);
  i = 49;
  printf("Integer as character: %c, %X\n", i, i);
  printf("Integer as floating-point: %E\n", (float) i);
  r = 97.512;
  printf("Floating-point as character: %c, %X\n", (char) r, (char) r);
  printf("Floating-point as integer: %d\n", (int) r);
  
  system("pause");
  
  return 0;
}

