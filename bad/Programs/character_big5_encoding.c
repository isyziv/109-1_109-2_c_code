/* This program will read a string of (Chinese) characters
   and then output their corresponding Big5 codes.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned char string[13];
  int i; 

  scanf("%s", &string);
  for (i=0; string[i] != '\0'; i++) 
    printf("%X ", string[i]);
  printf("\n");

  system("pause");
  return 0;
}

