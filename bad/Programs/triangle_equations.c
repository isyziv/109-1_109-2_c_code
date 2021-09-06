#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  
  const float PI = 3.14159;
  float side_AB, side_AC, side_BC, angle_A, angle_B, angle_C, s, area;
  
  do {
    printf("Enter the length of side AB: ");
    scanf("%f", &side_AB);
    printf("Enter the length of side AC: ");
    scanf("%f", &side_AC);
    printf("Enter the length of side BC: ");
    scanf("%f", &side_BC);
    printf("\n");
  } while (side_AB<=0 || side_AC<=0 || side_BC<=0 ||
           side_AB+side_AC<=side_BC ||
           side_AB+side_BC<=side_AC ||
           side_AC+side_BC<=side_AB);
  
  angle_A = acos((side_AB*side_AB+side_AC*side_AC-side_BC*side_BC) / (2*side_AB*side_AC))
            / PI * 180;
  printf("Angle A is %5.2f degrees.\n", angle_A);
  
  angle_B = acos((side_AB*side_AB+side_BC*side_BC-side_AC*side_AC) / (2*side_AB*side_BC))
            / PI * 180;
  printf("Angle B is %5.2f degrees.\n", angle_B);
  
  angle_C = acos((side_BC*side_BC+side_AC*side_AC-side_AB*side_AB) / (2*side_BC*side_AC))
            / PI * 180;
  printf("Angle C is %5.2f degrees.\n", angle_C);
  
  s = (side_AB + side_AC + side_BC) / 2;
  area = sqrt(s*(s-side_AB)*(s-side_AC)*(s-side_BC));
  printf("The area of triangle ABC is %5.2f.\n\n", area);             

  system("pause");
	return 0;
	}
