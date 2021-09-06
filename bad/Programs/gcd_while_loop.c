/* This program reads two positive integers and computes
   their greatest common divisor using Euclud's algorithm.
*/
#include <stdio.h>

int main(void) {
  int m, n;
  int num1, num2, temp, g;
 
  do {
    printf("Enter the first positive integer: ");
    scanf("%d", &m);
  } while (m<1);
 
  do {
    printf("Enter the second positive integer: ");
    scanf("%d", &n);
  } while (n<1);
  
  num1 = m;
  num2 = n;
  while (num1 % num2 != 0) {
    temp = num2;
    num2 = num1 % num2;
    num1 = temp;
  }
  g = num2;
  
  printf("\nThe greatest common divisor of %d and %d is %d.\n", m, n, g);
  
  system("pause");
  return 0; 
}
