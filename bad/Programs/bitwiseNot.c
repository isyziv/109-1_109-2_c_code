/* This program illustrates the computational effect of bitwise
   NOT operation.
*/
#include <stdio.h>

int main(void) {
  unsigned char x = 0x46, y;
  
  y = ~x;
  printf("x: %2X, y: %2X\n", x, y);
  
  system("pause");
  return 0; 
}
