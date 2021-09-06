#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A: mxn matrix,
   B: nxp matrix,
   C: mxp matrix.
   Compute C=AB.
*/
void matrix_product(int m, int n, int p, int A[100][100], int B[100][100], int C[100][100]) {
  int i, j, k;
    
  for (i=0; i<m; i++)
    for (j=0; j<p; j++) {
      C[i][j] = 0;
      for (k=0; k<n; k++) C[i][j] += A[i][k] * B[k][j];
    }
}

int main(void) {
  int A[100][100], B[100][100], C[100][100];
  int m, n, p;
  int i, j, k;
  
  srand(time(NULL));
  
  printf("Enter matrix size m: ");
  scanf("%d", &m);
  printf("Enter matrix size n: ");
  scanf("%d", &n);
  printf("Enter matrix size p: ");
  scanf("%d", &p);
    
  for (i=0; i<m; i++)
    for (j=0; j<n; j++) A[i][j] = rand() % 100;
    
  for (i=0; i<n; i++)
    for (j=0; j<p; j++) B[i][j] = rand() % 100;
    
  matrix_product(m, n, p, A, B, C);
  
  printf("\nMatrix A:\n");
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<p; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix C:\n");
  for (i=0; i<m; i++) {
    for (j=0; j<p; j++) printf("%6d ", C[i][j]);
    printf("\n");
  }
  
  printf("\n");
    
  system("pause");
  return 0; 
}
