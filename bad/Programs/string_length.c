/* Functions for computing string length.

   Returns the length of string str.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Iterative version
size_t strlen_ite(const char *str) {
  size_t length;

  for (length = 0; str[length] != '\0'; length++) ;
  return length; 
}

// Recursive version
size_t strlen_rec(const char *str) {
  if (*str=='\0') return 0;
  else return (strlen_rec(str+1) + 1); 
}

// The testing code includes the library version, the iterative vesion, 
// and the recursive version.
int main(void) {

  char A[]="1234444444567834567890abcde";
  char B[]="4444";
  
  printf("String A: %s, String B: %s\n\n", A, B);
  printf("Library version: Length of A: %d, Length of B: %d\n\n", strlen(A), strlen(B));
  printf("Iterative version: Length of A: %d, Length of B: %d\n\n", strlen_ite(A), strlen_ite(B));
  printf("Recursive version: Length of A: %d, Length of B: %d\n\n", strlen_rec(A), strlen_rec(B));
  
  system("pause");

  return 0; 
}




