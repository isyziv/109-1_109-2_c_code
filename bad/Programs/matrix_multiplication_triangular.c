#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: nxn lower triangular matrix,
   B: nxn upper triangular matrix,
   C: nxn matrix.
   Compute C=AB.
*/
void matrix_product_triangular(int n, int A[100][100], int B[100][100], int C[100][100]) {
  int i, j, k;
    
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {
      C[i][j] = 0;
      for (k=0; k<=min(i,j); k++) C[i][j] += A[i][k] * B[k][j];
    }
}

int main(void) {
  int A[100][100], B[100][100], C[100][100];
  int n;
  int i, j, k;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);
  
  // Get values for the lower triangular elements of matrix A.
  for (i=0; i<n; i++)
    for (j=0; j<=i; j++) A[i][j] = rand() % 100 + 1;
    
  // Get values for the upper triangular elements of matrix B.
  for (i=0; i<n; i++)
    for (j=i; j<n; j++) B[i][j] = rand() % 100 + 1;
    
  // Compute C = A X B.  
  matrix_product_triangular(n, A, B, C);
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<=i; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("    ");
    for (j=i; j<n; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix C:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%6d ", C[i][j]);
    printf("\n");
  }
  
  printf("\n");
    
  system("pause");
  return 0; 
}
