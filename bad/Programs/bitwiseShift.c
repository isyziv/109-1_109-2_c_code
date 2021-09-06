/* This program illustrates the computational effect of 
   bitwise right shift and left shift operations.
*/
#include <stdio.h>

int main(void) {
  unsigned char x = 0x46, y;

  y = x >> 4;
  printf("Bitwise right shift\tx: %02X, y: %02X\n", x, y);

  y = x << 4;
  printf("Bitwise left shift\tx: %02X, y: %02X\n", x, y);
  
  system("pause");
  return 0; 
}
