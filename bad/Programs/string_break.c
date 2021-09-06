#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char A[12], *B;

  
  strcpy(A, "abc8631def");
  B = strpbrk(A, "0123456789");
  printf("String A: %s, address of string A: %0X\n", A, A);
  printf("String B: %s, address of the string pointed by B: %0X\n", B, B);
  
  system("pause");

  return 0; 
}




