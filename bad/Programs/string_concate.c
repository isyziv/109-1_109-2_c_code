#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char A[] = "ABCDEF";
  char B[] = "123456789012345";

  printf("Address of string A: 0X%X;\n", A);
  printf("Address of string B: 0X%X;\n", B);
  printf("String A: %s\n", A);
  printf("String B: %s\n\n", B);
  
  strcat(B, A);
  printf("Address of string A: 0X%X;\n", A);
  printf("Address of string B: 0X%X;\n", B);
  printf("String A: %s\n", A);
  printf("String B: %s\n\n", B);
  
  system("pause");
  printf("\n");

  return 0; 
}




