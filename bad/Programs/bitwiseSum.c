/* This program illustrates addition of two positive integers
   such that non-zero bits do not overlap.
*/
#include <stdio.h>

int main(void) {
  int x=50432, y=125;
  int sum;
  
  sum = x | y;
   
  printf("x=%d, y=%d, sum=%d\n", x, y, sum);
  printf("x+y=%d\n", x+y);

  system("pause");
  return 0; 
}



