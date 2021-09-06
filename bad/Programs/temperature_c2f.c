/* This program illustrate the use of typedef. Two data types
   centigrade and fahrenheit are defined. The program simply
   reads a temperature in Centigrade and convert it to the
   degrees in Fahrenheit.
*/

#include <stdio.h>

typedef float centigrade;
typedef float fahrenheit;

int main(void) {

  centigrade cDeg;
  fahrenheit fDeg;
  
  printf("Please enter a temperature degree in Centigrade: ");
  scanf("%f", &cDeg);
  fDeg = cDeg * 9 / 5 + 32;
  printf("The temperature is %4.2f degrees Fahrenheit.\n", fDeg);
  
  system("pause");
  
  return 0;
}

