/* The recurive function of Fibonacci numbers.*/
#include <stdlib.h>
#include <stdio.h>

long fib(int n) {
  if (n==0) return 1;
  else if (n==1) return 1;
  else return fib(n-2)+fib(n-1);
}

int main(void) {
  int n;
  
  
  while (1) {
    printf("input n: ");
    scanf("%d", &n);
    if (n>-1) printf("Fib(%d) = %d\n\n", n, fib(n));
    else {system("pause"); return 0;}
  }
}
