/* The program computes the average of an element array. */

#include <stdio.h>

int main(void) {
  int score[10] = {78, 65, 90, 55, 82,
                   70, 49, 92, 82, 68};
  int i;
  float total = 0.0;

  for (i=0; i<10; i++)
    total += score[i];

  printf("Average score: %4.2f\n", total / 10.0);
  
  system("pause");
  return 0; 
}
