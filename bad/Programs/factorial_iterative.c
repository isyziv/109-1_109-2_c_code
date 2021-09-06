/* The iterative factorial function.
*/
#include <stdio.h>

int fact(int n) { 
  int i, ans=1;
  for (i=1; i<=n; i++) ans *= i;
  return ans;
}

int main(void) {
  int a;
  
  do {
    printf("Enter a positive interger a: ");
    scanf("%d", &a);
  } while (a < 1);
  printf("The factorial number of %d is %d.\n\n", a, fact(a));
  
  system("pause");
  return 0;
}
