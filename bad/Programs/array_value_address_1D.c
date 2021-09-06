/* This porgram shows the value and address of one-dimensional
   array score.
*/

#include <stdio.h>

int main(void) {
  int score[10] = {78, 65, 90, 55, 82, 70, 49, 92, 82, 68};

  printf("Content of score: 0X%X \n", score);
  printf("Address of score[0]: 0X%X\n\n", &score[0]);

  printf("Value of *score: %d \n", *score);
  printf("Value of score[0]: %d\n\n", score[0]);

  printf("Content of score+2: 0X%X \n", score+2);
  printf("Address of score[2]: 0X%X\n\n", &score[2]);

  printf("Value of *(score+2): %d \n", *(score+2));
  printf("Value of score[2]: %d\n", score[2]);

  return 0; 
}
