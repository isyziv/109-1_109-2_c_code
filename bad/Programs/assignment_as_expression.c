/* This program shows the use of assignments as expressions.
   It is not a good practice to wirte this kind of statements.
*/

#include <stdio.h>

int main(void) {
  int a = 2, b = 3, c = 5;
  int ans;
  
  ans = (a = a * b) + (b = a + c);
  printf("a=%d, b=%d, c=%d, ans=%d\n", a, b, c, ans);
  
  system("pause"); 
  return 0; 
}
