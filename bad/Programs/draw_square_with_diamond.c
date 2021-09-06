/* This program reads a number between 3 and 29 and draws
   a solid square of side n with a solid diamond embedded
   in the square. 
   Use '+' as a point of the square and '@' as a point of
   the diamond.
*/

#include <stdio.h>
#include <stdlib.h>

void printChar(int n, char c) {
 int i;
 
 for (i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
  int n, i, j;
  
  do {
    printf("Enter an integer between 3 and 29: ");
    scanf("%d", &n);
  } while ((n < 3) || (n > 29));
  
  printf("\n");
  for (i=0; i<n; i++) {
    printChar(4, ' ');
    printChar(n-i-1, '+');
    printChar(2*i+1, '@');
    printChar(n-i-1, '+');
    printf("\n");
  };
  
  for (i=n-2; i>=0; i--) {
    printChar(4, ' ');
    printChar(n-i-1, '+');
    printChar(2*i+1, '@');
    printChar(n-i-1, '+');
    printf("\n");
  }
  printf("\n");
    
  system("pause");
  return 0;
}
