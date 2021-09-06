/* This program will read the radius of a circle.
   The circumference and the area are computed and output.
   A constant PI is defined as 3.14159 to denote the mathematical
   constant of the ratio of a circle's circumference to its
   diameter. 
*/
 
#include <stdio.h>

int main(void) {

  float radius, circumference, area;
  const float PI = 3.14159;

  printf("Enter the radius: ");
  scanf("%f", &radius);
  circumference = 2 * PI * radius;
  area = PI * radius * radius;
  printf("Radius:\t\t%10.4f\t%10.4E\n", radius, radius);
  printf("Circumference:\t%10.4f\t%10.4E\n", circumference, circumference);
  printf("Area:\t\t%10.4f\t%10.4E\n", area, area);
  
  system("pause");
  return 0;
  }
