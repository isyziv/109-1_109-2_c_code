/* This program illustrate pass-by-value parameter
   passing scheme.
*/
#include <stdio.h>

void foo(int a) {
  a = a * 2;
  printf("a in foo: %d\n", a);
}

int main (void) {
  int n = 10;
  foo(n);
  printf("n in main: %d\n", n);
  
  system("pause");
  return 0;
}

