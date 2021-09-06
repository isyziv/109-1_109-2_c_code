/* The first for-loop reads the scores of the ten students.
   The second for loop sets the highest score to variable max. Then,
   ouptut the highest score. Variable i is the loop variable.
*/

#include <stdio.h>

int main(void) {
  int score[10];
  int max, i;
  
  for (i=0; i<10; i++) {
    printf("Enter the score of student No. %d: ", i+1);
    scanf("%d", &score[i]);
  }
  max = -1;
  for (i=0; i<10; i++) {
    if (max<score[i]) max = score[i];
  }
  printf("\nThe highest score is %d.\n", max);
  
  system("pause");
  return 0; 
}
