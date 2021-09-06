/* The program will set Big5 codes of Chinese characters
   資訊工程學系 to a character array and then output this
   Chinese string. 
*/

#include <stdio.h>

int main(void) {
  unsigned char string[13];

  string[0] = '\xB8';
  string[1] = '\xEA';
  string[2] = '\xB0';
  string[3] = '\x54';
  string[4] = '\xA4';
  string[5] = '\x75';
  string[6] = '\xB5';
  string[7] = '\x7B';
  //string[8] = '\xBE';
  string[9] = '\xC7';
  string[10] = '\xA8';
  string[11] = '\x74';
  //string[12] = '\0';
  printf("%s\n", string);
  
  return 0;
}
