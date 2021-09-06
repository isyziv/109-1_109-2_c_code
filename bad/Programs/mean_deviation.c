/* The first for-loop reads the scores of the 15 students.
   The second for-loop adds the total score.
   Then the mean (mu) is computed.
   The third for-loop adds summation part of the standard deviation.
   Then the standard deviation (sigma) is computed.
*/

#include <stdio.h>
#include <math.h>

int main(void) {
  int score[15];
  int total, i;
  float mu, sigma, diff;
  
  for (i=0; i<15; i++) {
    printf("Enter the score of student No. %d: ", i+1);
    scanf("%d", &score[i]);
  }
  
  total = 0;
  for (i=0; i<15; i++) {
    total = total + score[i];
  }
  mu = total / 15.0;
  
  total = 0;
  for (i=0; i<15; i++) {
    diff = score[i] - mu;
    total = total + diff * diff;
  }
  sigma = sqrt(total / 15.0);
  
  printf("\nThe mean is %4.2f.\n", mu);
  printf("The standard deviation is %4.2f.\n\n", sigma);
  
  system("pause");
  return 0; 
}
