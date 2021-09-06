/* The program is to swap two neighboring bits starting from the the most significant bits.
   If x is x_31x_30x_29x_28...x_3x_2x_1x_0, then after swapping the neighboring bits 
   the result becomes x_30x_31x_28x_29...x_2x_3x_0x_1. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  unsigned int x, y;
  
  printf("Enter an unsigned integer value of x (8 hexadecimal digits): ");
  scanf("%X", &x);
  
  y = ((x << 1) & 0XAAAAAAAA) | ((x >> 1) & 0x55555555);
  
  printf("The input data:       x=0X%08X\n", x);
  printf("The swapping result:  y=0X%08X\n\n", y);
  
  system("pause");
  return 0; 
}
