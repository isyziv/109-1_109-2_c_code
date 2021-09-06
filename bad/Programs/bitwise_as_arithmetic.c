/* Applying bitwise logical operations as arithmetic operations */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  unsigned int x, y, z;
  
  // Read a value and set it to variable x.
  // Set y to be the value of x by setting the higher 16 bits to 0
  // and preserving the lower 16 bits.
  // That is, if x is x[31]x[30]...x[16]x[15]...x[1]x[0],
  // then set y to 0000000000000000x[15]...x[1]x[0].
  printf("Enter an integer value of x (base 10): ");
  scanf("%d", &x);
  y = x & 0x0000FFFF;
  printf("Setting the higher 16 bits to 0 and preserving the lower 16 bits (base 16):\n");
  printf("x=0X%08X, y=0X%08X\n\n", x, y);
  
  // Read a value and set it to variable x.
  // Set y to be the value of x by setting the odd bits to 1 and preserving the even bits.
  // That is, if x is x[31]x[30]x[29]x[28]...x[3]x[2]x[1]x[0],
  // then set y to x[31]1x[29]1...x[3]1x[1]1
  printf("Enter an integer value of x (base 10): ");
  scanf("%d", &x);
  y = x | 0x55555555;
  printf("Setting the he odd bits to 1 and preserving the even bits (base 16):\n");
  printf("x=0X%08X, y=0X%08X\n\n", x, y);
  
  // Read two values and set tehm to variables x and y (less than 65536).
  // Set variable z to x/512+y*65536.
  printf("Enter an integer value of x (base 10, less than 65536): ");
  scanf("%d", &x);
  printf("Enter an integer value of y (base 10, less than 65536): ");
  scanf("%d", &y);
  z = x >> 9 | y << 16;
  printf("Set variable z to x/512+y*65536 (base 16):\n");
  printf("x=0X%08X, y=0X%08X, z=0X%08X\n\n", x, y, z);
  
  system("pause");
  return 0; 
}
