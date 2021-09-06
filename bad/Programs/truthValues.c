/* This program illustrates truth values and logical
   operations of C programming languages.
*/
#include <stdio.h>

int main(void) {
  printf("Truth: %d\n", 1==1);
  printf("False: %d\n", 1!=1);
  printf("Negation: %d\n", !(1==1));
  printf("Conjunction: %d\n", 1==1 && 1>0);
  printf("Disjunction: %d\n", 1!=1 || 1>0);
  system("pause");
  return 0; 
}



