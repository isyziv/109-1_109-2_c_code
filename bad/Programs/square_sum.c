// This program ask you to enter a sequence of
// five numbers. Then, it sums up the square of 
// each number and print the result.

#include <stdio.h>

int main(void) {

  int number[5]; // Integer array declaration
  int i, sum0 = 0, sum1 = 0;    // Integer declarations
  
// Enter five integer values.
  printf("\n");
  printf("Enter the first number:  ");
  scanf("%d", &number[0]);
  printf("Enter the second number: ");
  scanf("%d", &number[1]);
  printf("Enter the thrid number:  ");
  scanf("%d", &number[2]);
  printf("Enter the foruth number: ");
  scanf("%d", &number[3]);
  printf("Enter the fifth number:  ");
  scanf("%d", &number[4]);
  printf("\n");
  
// Compute the square sum using a sequence of addition operations.
  sum0 = number[0] * number[0] + number[1] * number[1] +
         number[2] * number[2] + number[3] * number[3] +
         number[4] * number[4];
  printf("1. The square sum using a sequence of addition operations: %d\n", sum0);
  
  
// Compute the square sum using an iterative for loop.
  for (i=0; i<5; i++) {
    sum1 = sum1 + number[i] * number[i];
  }
  printf("2. The square sum using an iterative for loop: %d\n\n", sum1);
  
  exit(1);
}
