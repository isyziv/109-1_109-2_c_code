#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char A[8], B[8];

  printf("Address of A: 0X%0X\n", A);
  printf("Address of B: 0X%0X\n\n", B);
  
  strcpy(B, "abcde");  
  printf("String B: %s, length of string B: %d\n", B, strlen(B));
  system("pause");
  printf("\n");
  
  strcpy(A, B);
  printf("String A: %s, length of string A: %d\n", A, strlen(A)); 
  system("pause");
  printf("\n");
  
  strcpy(B, "abcdefgh");
  printf("String B: %s, length of string B: %d\n", B, strlen(B));
  system("pause");
  printf("\n");
  
  strcpy(A, B);
  printf("String A: %s, length of string A: %d\n", A, strlen(A));
  system("pause");

  return 0; 
}




