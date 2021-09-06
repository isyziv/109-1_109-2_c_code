/* The iterative function of Fibonacci numbers. */
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int n, i, last1, last2, result;;
  
  
  while (1) {
    printf("input n: ");
    scanf("%d", &n);
    if (n>=0) {
      if (n==0) result = 1;
      else if (n==1) result = 1;
      else {
        last1 = 1;
        last2 = 1;
        for (i=2; i<=n; i++) {
          result = last1 + last2;
          last2 = last1;
          last1 = result; } }
      printf("Fib(%d) = %d\n\n", n, result); }
    else {
      system("pause");
      return 0; }      
  }
}
