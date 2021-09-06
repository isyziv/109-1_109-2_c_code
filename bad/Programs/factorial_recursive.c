/* The recursive factorial function.
*/
#include <stdio.h>

int fact(int n) { 
  if (n == 1) return 1;
  else return (n * fact(n - 1));
}

int main(void) {
  int a;

  do {
    printf("Enter a positive integer a: ");
    scanf("%d", &a);
  } while (a < 1);
  printf("The factorial number of %d is %d.\n\n", a, fact(a));
  
  system("pause");
  return 0;
}
