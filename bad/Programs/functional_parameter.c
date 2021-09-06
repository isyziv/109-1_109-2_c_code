#include <stdio.h>
#include <stdlib.h>

int square(int x) {
  return x * x;
}

int cubic(int x) {
  return x * x * x;
}

int sigma(int low, int high, int (*f) (int)) {
  int sum = 0;
  int k;
  
  for (k=low; k<=high; k++) sum += f(k);
  return sum;
}

int main(void) {
  printf("Summation of square 1 to 10: %d\n", sigma(1, 10, square));
  printf("Summation of cubic 1 to 10: %d\n", sigma(1, 10, cubic));
  return 0;
}

