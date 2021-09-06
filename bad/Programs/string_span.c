#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  char string[]="100 Wenhua Rd., 40724 Taichung, Taiwan; 04-24517250", *A;

  // Find the length of the first number string.
  printf("The length the 1st numeral string is %d.\n", strspn(string, "1234567890"));
  system("pause");
  
  // Find the length of the second numeral string. (incorrect code)
  A = strpbrk(string, "1234567890") + strspn(string, "1234567890");
  printf("\nThe length of the 2nd numeral string is %d.\n", strspn(A, "1234567890"));
  system("pause");
  printf("\nWhy the length is 0?\n");
  system("pause");
  
  // Find the length of the second number string. (correct code)
  A = strpbrk(string, "1234567890") + strspn(string, "1234567890");
  A = strpbrk(A, "1234567890");
  printf("\nThe length of the 2nd numeral string is %d.\n", strspn(A, "1234567890"));
  system("pause");
  
  // Find the length of the third number string.
  A = strpbrk(A, "1234567890") + strspn(A, "1234567890");
  A = strpbrk(A, "1234567890");
  printf("\nThe length of the 3rd numeral string is %d.\n", strspn(A, "1234567890"));
  system("pause");
  
  // Find the length of the fourth number string.  
  A = strpbrk(A, "1234567890") + strspn(A, "1234567890");
  A = strpbrk(A, "1234567890");
  printf("\nThe length of the 4th numeral string is %d.\n", strspn(A, "1234567890"));
  system("pause");

  return 0; 
}
