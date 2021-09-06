/* This program reads a number between 3 and 29 and draws
   a diamond of side n.
*/

#include <stdio.h>
#include <stdlib.h>

void printChar(int n, char c) {
 int i;
 
 for (i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
  int n, i;
  
  do {
    printf("\n Enter an integer between 3 and 29: ");
    scanf("%d", &n);
  } while ((n < 3) || (n > 29));
  
  printf("\n\n");
  printChar(n-1+10, ' ');
  printChar(1, '*');
  printf("\n");
  
  for (i = 1; i < n; i++) {
    printChar(n-i-1+10, ' ');
    printChar(1, '*');
    printChar(2*i-1, '@');
    printChar(1, '*');
    printf("\n");
  }
  
  for (i = n-2; i > 0; i--) {
    printChar(n-i-1+10, ' ');
    printChar(1, '*');
    printChar(2*i-1, '@');
    printChar(1, '*');
    printf("\n");
  }
  
  printChar(n-1+10, ' ');
  printChar(1, '*');
  printf("\n\n");
    
  system("pause");
  return 0;
}
