/* The program declares a character array of size 10.
   The array is initialized to string "ABC". The original
   an manipulated strings are printed out.   
*/

#include <stdio.h>

int main(void) {
  char string[10] = {'A', 'B', 'C', '\0'};

  printf("The original string: %s\n", string);
  string[3] = '\t';    // horizontal tab
  string[4] = '\\';    // baclslash
  string[5] = '\"';    // double quote
  string[6] = 'X';     // character X
  string[7] = '\131';  // character Y
  string[8] = '\x5A';  // character Z
  string[9] = '\0';    // null
  printf("The new string:      %s\n", string);
  
  return 0;
}

