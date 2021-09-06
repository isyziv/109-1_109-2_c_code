/* This program reads a number between 2 and 30 and draws
   a square of side n.
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
    printf("\n Enter an integer between 2 and 30 (including): ");
    scanf("%d", &n);
  } while ((n < 2) || (n > 30));
  
  printf("\n");
  printChar(4, ' ');
  printChar(n, 'X');
  printf("\n");
  
  for (i = 0; i < n - 2; i++) {
    printChar(4, ' ');
    printChar(1, 'X');
    printChar(n-2, ' ');
    printChar(1, 'X');
    printf("\n");
  }
  
  printChar(4, ' ');
  printChar(n, 'X');
  printf("\n\n");
    
  system("pause");
  return 0;
}
