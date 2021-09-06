#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A: mxn matrix,
   V: column vector of length n,
   U: column vector of length m,
   U = AV.
*/
void matrix_vector_product(int m, int n, int A[100][100], int V[100], int U[100]) {
  int i, j;
  
  for (i=0; i<m; i++) {
    U[i] = 0;
    for (j=0; j<n; j++) {
      U[i] = U[i] + A[i][j] * V[j];
    }
  }
}

int main(void) {
  int A[100][100], V[100], U[100];
  int m, n;
  int i, j;
  
  srand(time(NULL));
  
  printf("Enter a positive integer m (between 3 and 100): ");
  scanf("%u", &m);
  printf("Enter a positive integer n (between 3 and 100): ");
  scanf("%u", &n);
  
  for (i=0; i<m; i++) 
    for (j=0; j<n; j++) A[i][j] = rand() % 100;
  
  for (i=0; i<n; i++) V[i] = rand() % 100;  
  
  matrix_vector_product(m, n, A, V, U);
  
  printf("\nMatrix A:\n");
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nVector V is: ");
  for (i=0; i<n; i++) {
    printf("%3d  ", V[i]);
  }
  printf("\n");
  
  printf("\nVector U is: ");
  for (i=0; i<m; i++) {
    printf("%6d  ", U[i]);
  }
  printf("\n\n");
  
  system("pause");
  return 0; 
}
