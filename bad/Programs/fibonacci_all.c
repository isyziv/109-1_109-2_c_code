#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------------------- recursive -------------------------------------- */
unsigned long fib_recursive(int n) {

  if(n==0) return 1; 
  if(n==1) return 1;
  else return fib_recursive(n-1)+fib_recursive(n-2);
}

/* ---------------------- iterative -------------------------------------- */

unsigned long fib_iterative(int n) {
  unsigned long last1=1, last2=1, curr;
  int i;
    
  if(n<=1) return n;
	else {
    for(i=2;i<=n;i++) {
      curr = last1 + last2;
      last2 = last1;
      last1 = curr;
    }
    return curr;
	}
}

/* ---------------------- fast recursive -------------------------------------- */

unsigned long fib_fast(int n)
{
    long b=n/2;

    if (n==0) return 1;
    if (n==1) return 1;        
    if (n==2) return 2; 
    else
      if (n % 2 == 0) return fib_fast(b+1)*fib_fast(b)-fib_fast(b-1)*fib_fast(b-2);
      else return fib_fast(b+1)*fib_fast(b)+fib_fast(b)*fib_fast(b-1);
}

int main(void)
{
  clock_t start, finish;
	double  duration;
	int i;
  int n;
  unsigned long result;
	unsigned long count;

  while (1) {
    duration = 0.0; 

    printf( "Enter n for fib >> ");       
    scanf("%d",&n);
    if (n<0) break;

    printf( "Enter the repetitive count: >> ");       
    scanf("%d",&count);
    printf("\n");

/* Recursive Fibonacci algorithm */
    start = clock();
    for (i=0; i<count; i++) result = fib_recursive(n);
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "Recursive Fibonacci: %d time(s), %12.10f seconds\n", count, duration);
    printf( "Result: %d \n\n", result);

/* Iterative Fibonacci algorithm */
    start = clock();
    for (i=0; i<count; i++) result = fib_iterative(n);
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "Iterative Fibonacci: %d time(s), %12.10f seconds\n", count, duration);
    printf( "Result: %d \n\n", result);

/* Fast recursive Fibonacci algorithm */
    start = clock();    
    for (i=0; i<count; i++) result = fib_fast(n);
    finish = clock();
     
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Fast recursive Fibonacci: %d time(s), %12.10f seconds\n", count, duration);
    printf("Result: %d \n\n", result); 
  };
  
  system("pause");
  return 0;
}
