/* The fast recurive function of Fibonacci numbers.*/
#include <stdlib.h>
#include <stdio.h>

long fib(int n) {
  if (n==0) return 1;
  if (n==1) return 1;        
  if (n==2) return 2;  
  if (n % 2 == 0) {
    return (fib(n/2+1)* fib(n/2)- fib(n/2-1)* fib(n/2-2));
    } 
  else {
    return (fib(n/2+1)* fib(n/2)+ fib(n/2)* fib(n/2-1));
  }
}

int main() {
  int n;
    
  while (1) {
    printf("input n: ");
    scanf("%d", &n);
    if (n>-1) printf("Fib(%d) = %d\n\n", n, fib(n));
    else {system("pause"); return 0;}
  }
}
