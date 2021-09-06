#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char A[8], B[8];

  printf("Enter string A: ");
  scanf("%s", A);
  printf("Enter string B: ");
  scanf("%s", B);
  
  printf("\nAddress of A: %X\n", &A);
  printf("Address of B: %X\n\n", &B);
  printf("String A: %s\n", A);
  printf("String B: %s\n", B);
  
  system("pause");
  return 0; 
}

