/* The program reads three coefficients a, b, and c of equation
   a*x*x+b*x+c=0. If b*b-4ac is greater than or equal to zeor,
   the real roots of the equation is computed and printed;
   otherwise, the complex roots of the equation is computed and printed;
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  float a, b, c;
  float temp;
 
  printf("�Ѥ@���G����{�� ax**2+bx+c=0.\n");
  printf("Ū�J�T�ӫY�� a, b, �M c: ");
  scanf("%f %f %f", &a, &b, &c);
  printf("\n�@���G����{�� %fx**2+%fx+%f=0 ���ڬ��G\n    ",
         a, b, c); 
  temp = b * b - 4 * a * c;
  if (temp >= 0) {
    printf("%f �M %f.\n\n",
           (-b + sqrt(temp)) / (2 * a), (-b - sqrt(temp)) / (2 * a)); 
  }
  else {
    printf("%f+%fi �M %f-%fi.\n\n",
           -b / (2 * a), sqrt(-temp) / (2 * a),
           -b / (2 * a), sqrt(-temp) / (2 * a));
  } 
 
  system("pause");
  return 0;
}
