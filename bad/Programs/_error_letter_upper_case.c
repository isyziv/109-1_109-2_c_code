/* This program will print upper lettes from A to Z
   six characters a line. If the last line contains
   less than six letters, it will be filled in with
   the hash sign #. 
*/ 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char c;
  int i, j;

  // Variable i is a counter to recodrd the number of characters
  // printed in a line. It is initialized to zero. 
  
  // The loop will print letter 'A' to 'Z'. In each iteration:
  // 1. A character is output:
  // 2. Increment counter i by 1. 
  // 3. If counter i is 6, output a newline and set i to 0. 
  for (c = 'A'; c <='Z'; c++) {
    printf("%c", c);
    i++;
    if (i == 6) {
      printf("\n");
      i == 0;
    }
  }
  // At the end of the previous loop, the value of variable i is
  // the number of characters being output in the last line.
  // If i is 0, it means the last line contains six characters.
  // If i is not 0, it means the last line contains less than six
  // characters. Then, 6-i hash signs will be output. 
  if (i != 0) {
    for (j = 0; j < 6 - i; j++) printf('#');
    printf("\n");
  }
  
  system("pause");
  return 0;
}
