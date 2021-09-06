/* This program illustrates the equivalence of arithmetic operations
   multiplication and divsion with right shift, left shift and
   conjunction operations.
*/
#include <stdio.h>

int main(void) {
  unsigned int x = 3455;
  
  printf("x=%d, x<<6=%d, x*64=%d\n", x, x<<6, x*64);
  
  printf("x=%d, x>>6=%d, x/64=%d\n", x, x>>6, x/64); 
  
  printf("x=%d, x&63=%d, x%%64=%d\n", x, x&63, x%64); 
  
  system("pause");
  return 0; 
}
