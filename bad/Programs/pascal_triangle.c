/* Read a positive integer as the degree of a Pascal triangle.
   Print the Pascal triangle of the given degree.
*/

#include <stdio.h>
#include <stdlib.h>

int combination(int n, int r) {
  int i;
  int result = 1;
  
  if (r>n/2) r = n - r;
  for(i=1; i<=r; i++) result = result * (n-i+1) / i;
        
  return result;
}

int main() {
  int degree;
  int i, j;
    
  do {
    printf("\n Enter an integer between 0 and 15 (including): ");
    scanf("%d", &degree);
  } while ((degree < 0) || (degree > 15));
    
  printf("\n");
  for(i=0; i<=degree; i++) {
    for(j=0; j<=i; j++) {
      printf("%4d ", combination(i,j));
    }
    printf("\n");
  } 
  printf("\n");
    
  system("pause");
  return 0;    
}

