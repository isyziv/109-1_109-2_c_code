/* This program is to show the difference of various
   integer data types. When an interger variable of a
   large value is assigned to a variable of short integer
   data type. It causes overflow, i.e., the value is too
   large for a short integer.  
*/ 
#include <stdio.h>

int main(void) {
  int i;
  short j; 
  long k; 

  i = 158423; 
  printf("normal integer: %d\n",           i);
  j = i; 
  printf("short integer (overflow): %d\n", j);
  k = i; 
  printf("long integer:      %d\n",        k);
  
  return 0;
}

