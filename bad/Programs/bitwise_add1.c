/* This program uses bitwise operation to implement
   ADD1 operation of an unsigned integer.
*/
#include <stdio.h>

int main(void) {
  unsigned m, n, carry;
 
  printf("Enter an unsigned integer: ");
  scanf("%u", &m);
  
  n = m;
  carry = 1;
  while ((n & carry) != 0) {
    n = n ^ carry;
    carry = carry << 1;
  }
  n =n | carry;
  
  printf("The result of %u adding 1 is: %u\n", m, n);
  
  system("pause");
  return 0; 
}
