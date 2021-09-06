/* This program is to show the maximum and minimum values
   of integer data type. 
*/ 

#include <stdio.h>

int main(void) {
  int i;

  i = 2147483647; // Set i to the maximum value.
  printf("maximum integer value: %d\n", i);
  i = 2147483648; // Set i to a value greater then the maximum value.
  printf("integer overflow:      %d\n", i); // Overflow occurs. 
  i = -2147483648; // Set i to the minimum value.
  printf("minimum integer value: %d\n", i);
  i = -2147483649; // Set i to a value less then the minimum value.
  printf("integer underflow:     %d\n", i); // Underflow occurs.
  
  return 0;
}

