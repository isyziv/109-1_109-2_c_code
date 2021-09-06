/* This program illustrates the computational effect of 
   bitwise AND, OR, and XOR operations.
*/
#include <stdio.h>

int main(void) {
  unsigned char x = 0x46, y;
  
  y = x & 0x00;
  printf("Bitwise AND\tx: %02X, y: %02X\n", x, y);
  
  y = x | 0xFF;
  printf("Bitwise  OR\tx: %02X, y: %02X\n", x, y);  
  
  y = x ^ 0xFF;
  printf("Bitwise XOR\tx: %02X, y: %02X\n", x, y);  
  
  system("pause");
  return 0; 
}
