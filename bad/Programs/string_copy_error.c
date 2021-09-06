#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char A[10], B[10];

  
  strcpy(B, "abcdefghijkl");
  strcpy(A, B);
  
  printf("String A: %s\n", A);
  printf("String B: %s\n", B);
  
  system("pause");

  return 0; 
}




