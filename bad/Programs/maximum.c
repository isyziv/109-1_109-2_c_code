/* This program illustrates the use of if-then-else
   statement to set max as the maximum value of x and y.
*/
#include <stdio.h>

int main(void) {
  int x, y;
  int max;
  
  printf("Enter x and y: ");
  scanf("%d %d", &x, &y);
  
  if (x >= y) max = x;
  else max = y;
   
  printf("Maximum: %d\n", max);
  system("pause");
  return 0; 
}



