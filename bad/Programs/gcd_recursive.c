/* This program reads two positive integers and computes
   their greatest common divisor using Euclud's algorithm.
*/
#include <stdio.h>

int gcd(int num1, int num2) {
  if (num1 % num2 == 0) return num2;
  else return gcd(num2, num1 % num2);
}

int main(void) {
  int m, n;
  int g;
 
  do {
    printf("Enter the first positive integer: ");
    scanf("%d", &m);
  } while (m<1);
 
  do {
    printf("Enter the second positive integer: ");
    scanf("%d", &n);
  } while (n<1);
  
  g = gcd(m, n);
  
  printf("\nThe greatest common divisor of %d and %d is %d.\n", m, n, g);
  
  system("pause");
  return 0; 
}
