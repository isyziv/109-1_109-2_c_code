// This program ask you to enter values for
// some integer variables. Then, it performs
// various arithmetic computation and outputs
// the computational results.

#include <stdio.h>

int main(void) {

  int u, v, w, x, y, z, ans; // Integer declarations.
  float ans1;                // Floating point number declaration.
  
// Enter the values of variable u, v, w, x, y, and z.
  printf("\n");
  printf("Enter the value of u: ");
  scanf("%d", &u);
  printf("Enter the value of v: ");
  scanf("%d", &v);
  printf("Enter the value of w: ");
  scanf("%d", &w);
  printf("Enter the value of x: ");
  scanf("%d", &x);
  printf("Enter the value of y: ");
  scanf("%d", &y);
  printf("Enter the value of z: ");
  scanf("%d", &z);
  printf("\n");
  
  ans = u + v - 5 * w;
  printf("u + v - 5 * w = %d\n\n", ans);
  
  ans = x / 3;                   // Integer division
  printf("x / 3 = %d\n\n", ans);
  
  ans1 = x / 3.0;                // Floating point number division
  printf("x / 3 = %f\n\n", ans1);
  
  ans = y - 20;
  printf("y - 20 = %d\n", ans);
  y = y * y;
  printf("Variable y is set to y*y which is of value %d\n", y);
  ans = y - 20;
  printf("y - 20 = %d\n\n", ans);
  
  ans = z * z + 6 * z + 8;
  printf("z * z + 6 * z + 8 = %d\n", ans);  
  ans = (z + 2) * (z + 4);
  printf("(z + 2) * (z + 4) = %d\n\n", ans);
  
  if (u > v) {                            // Conditional statement
    printf("maximun(u,v) = %d\n\n", u); } // When the condition is true.
  else {
    printf("maximun(u,v) = %d\n\n", v); } // When the condition is false.
    
  system("pause");
  
  exit(1);
}
