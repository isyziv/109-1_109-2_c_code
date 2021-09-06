#include <stdio.h>

int main(void)
{

  unsigned char big5[1];
  int i = 0;
  big5[0] = '\xB3';
  big5[1] = '\x5C';
  printf("%s", big5);
  printf("¯§Þ³");
  return 0;
}
