/* This porgram reads one character a time up to 30 charcters or
   encountering a terminating character '|'. Then, the character
   string is printed.
*/

#include <stdio.h>

int main(void) {
  char c[31];
  int i = 0;
  
  do {
    scanf("%c", &c[i]);
  } while (i<30 && c[i++]!='|');  
  c[i] = '\0';
  printf("\nThe character string is:\n%s\n", c);
  
  system("pause");
  return 0; 
}
