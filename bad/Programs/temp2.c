#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int abc(int *k) {
  *k +=4;
  return 3 * (*k) - 1; }

int main() {
  int i = 10, j = 10;
  int old_i = i, old_j = j; 
  int abc_1, abc_2;
  int result1_l_to_r, result1_r_to_l, result2_l_to_r, result2_r_to_l; 
  
  abc_1 = abc(&i);
  abc_2 = abc(&j);
   
  result1_l_to_r = (old_i / 2) + abc_1;
  result1_r_to_l = (i / 2) + abc_1;
  result2_l_to_r = abc_2 + (j / 2);
  result2_r_to_l = abc_2 + (old_j / 2);
  
  printf("%d %d %d %d\n\n",  result1_l_to_r, result2_l_to_r, result1_r_to_l, result2_r_to_l);
  system("pause"); 
}

