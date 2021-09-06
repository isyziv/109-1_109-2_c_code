/* Write a C program to read the values of variables x, y, and z.
   Compute and print the resulting value of f(x, y, z).
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  float x, y, z, f;
  do {
    printf("Enter the values of x, y, and z: ");
    scanf("%f %f %f", &x, &y, &z);
  
    if (x==0 || y==0 || z==0) {
      f = 0.0;
    }
    else {
      f = (((z*z*z-5.0*x*y)/(x*x+y*y+z*z))+6.0*(x*x*y-y*z*z))/(x*y*z);
    }
  
    printf("The result of f(%6.4f, %6.4f, %6.4f) is %6.4f. \n\n", x, y, z, f);
    printf("-----------------------------------------------------------\n\n");
  } while (x!=0 || y!=0 || z!=0);
  
  system("pause");
  return 0; 
}
