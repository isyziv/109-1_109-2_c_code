/* This program will print lower lettes from z back to a
   and, then, digits 0 to 9, five characters a line. If
   the last line contains less than five letters, it will
   be filled in with the dollar sign $. 
*/

#include <stdio.h>

int main(void) {
  char c;
  int i, j;

  i = 0;
  for (c = 'z'; c >='a'; c--) {
    printf("%c", c);
    i++;
    if (i == 5) {
      printf("\n");
      i = 0;
    }
  }
  for (c = '0'; c <='9'; c++) {
    printf("%c", c);
    i++;
    if (i == 5) {
      printf("\n");
      i = 0;
    }
  }
  if (i != 0) {
    for (j = 0; j < 5 - i; j++) printf("$");
    printf("\n");
  }
  
  system("pause");
  return 0;
}
