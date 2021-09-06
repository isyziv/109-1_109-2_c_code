/* This program is to solve a system of three-variable
   linear equations using Cramer's rule. The program includes
   three steps.
   1. Read three sets of numbers. Each set has four floating-point
      numbers representing the three coefficients and one constant
      term of an equation.
   2. If the coefficient determinant is not zero, compute the
      solutions of x, y, and z using Cramer's rule; otherwise,
      report a message "The equation system has no solution or
      infinite number of solutions."
   3. Substitute the solutions of x, y, and z to the equation
      system to verify the correctness of the solutions.
*/
#include <stdio.h>
#include <math.h>

int main(void) {

  const float epsilon = 1.0e-4;
  float a1, b1, c1, d1;
  float a2, b2, c2, d2;
  float a3, b3, c3, d3;
  float x, y, z, denominator;

  // Read the coefficients and constant terms of the three equations.
  printf("Enter the three coefficients and constant term of the first equation:\n    ");
  scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
  printf("Enter the three coefficients and constant term of the second equation:\n    ");
  scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
  printf("Enter the three coefficients and constant term of the third equation:\n    ");
  scanf("%f %f %f %f", &a3, &b3, &c3, &d3);
  
  // Print the the system of equations.
  printf("The system of linear equations is:\n");
  printf("    %4.2fx + %4.2fy + %4.2fz = %4.2f\n", a1, b1, c1, d1);
  printf("    %4.2fx + %4.2fy + %4.2fz = %4.2f\n", a2, b2, c2, d2);
  printf("    %4.2fx + %4.2fy + %4.2fz = %4.2f\n\n", a3, b3, c3, d3);
  
  // Compute the solution using Cramer's rule.
  denominator = a1*b2*c3+b1*c2*a3+c1*a2*b3-a1*c2*b3-b1*a2*c3-c1*b2*a3;
  if (fabs(denominator) >= epsilon) {
    x = (d1*b2*c3+b1*c2*d3+c1*d2*b3-d1*c2*b3-b1*d2*c3-c1*b2*d3)/denominator;
    y = (a1*d2*c3+d1*c2*a3+c1*a2*d3-a1*c2*d3-d1*a2*c3-c1*d2*a3)/denominator;
    z = (a1*b2*d3+b1*d2*a3+d1*a2*b3-a1*d2*b3-b1*a2*d3-d1*b2*a3)/denominator;
    printf("**** The solution is x=%4.2f, y=%4.2f, z=%4.2f\n\n", x, y, z);
    // Test correctness of the solution.
    if (fabs(a1*x+b1*y+c1*z-d1) < epsilon &&
        fabs(a2*x+b2*y+c2*z-d2) < epsilon &&
        fabs(a3*x+b3*y+c3*z-d3) < epsilon) {
      printf("**** The solution is correct.\n\n");
    }
    else {
      printf("**** The solution is incorrect.\n");
      printf("      error1: %f, error2: %f, error3: %f\n\n",
             fabs(a1*x+b1*y+c1*z-d1),
             fabs(a2*x+b2*y+c2*z-d2),
             fabs(a3*x+b3*y+c3*z-d3));
    }
	}
	else {
	  printf("The equation system has no solution or infinite number of solutions.\n\n");
	}
	
	system("pause");
	return 0;
}


