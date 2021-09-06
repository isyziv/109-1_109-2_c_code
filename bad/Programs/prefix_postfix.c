/* This program shows the effect of prefix and postfix
   operations. In a prefix operation, the new value will be
   used in the addition; in a postfix operation, the old
   value will be used in the addition. 
*/ 

#include <stdio.h>

int main(void) {
  int a = 10;
  int b = 10; 
  int c, d;
  
  c = ++a + 5;
  d = b++ + 5; 
  printf("a: %d, b: %d\n", a, b);
  printf("c: %d, d: %d\n", c, d);
  
  system("pause"); 
  return 0; 
}
