/* This program shows a static vairable is a history-sensitive.
   Variable a is decalred as a static variable and variable b
   is a non-static variable. When foo() is first called in main(),
   variable a is initialized to 0, and then a is set to a+1, i.e.,
   1. In the second and third calls to foo(), vairable a is not
   initialized, and its previous is used. Therefore, it is history-
   sensitive. However, variable b is initialized to 0 everytime when
   foo() is called.  
*/
 
#include <stdio.h>

void foo(void) {
  static int a = 0;
  int b = 0; 
  
  a = a + 1;
  b = b + 1;  
  printf("a: %d, b: %d\n", a, b);
}

int main(void) {
  foo();
  foo();
  foo();
  return 0; 
}
