/* This program is to demostrate integer and floating-point
   format specifier. The number after % spefifies the minimum
   width. The number specifies the precision after the decimal
   point.
   Hence, specifier "%4d" will print an integer of minimum width
   4. If the integer value is less than four digits, spaces will
   be filled at the beginning. If the intege value is more than
   four digits, all digits will output.
   Specifier "%6.2f" will print a floating point number using the
   fixed-point format of 6 poisitons and two digits after the
   decimal point. If the total length is less than 6, spaces will
   be filled at the beginning. If the integer part is more than
   three digits, all integer disgits will be output. 
*/ 

#include <stdio.h>

int main(void) {

  printf("%4d\n", 12); // Two spaces at the beginning. 
  printf("%4d\n", -8); // Two spaces at the beginning. 
  printf("%4d\n", 12345); // Total five digits are output. 
  printf("%6.2f\n", 2.5); // Two leading spaces and on trailing zero are output. 
  printf("%6.2f\n", 32.533); // One leading space and only two digits after the decimal point are output. 
  printf("%6.2f\n", 3232.533); // All digits of the integer part are output. 
  
  return 0;
}

