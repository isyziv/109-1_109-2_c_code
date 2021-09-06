#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A is an mxn matrix and B is an nxm matrix.
// Set matrix B to be the transposition of matrix A.
void transpose(int m, int n, int A[100][100], int B[100][100]) {
  int i, j;
  
  for (i=0; i<m; i++)
    for (j=0; j<n; j++)
      B[j][i] = A[i][j];
}

int main(void) {
  int A[100][100], B[100][100];
  int m, n;
  int i, j;
  
  srand(time(NULL));
  
  printf("Enter matrix size m: ");
  scanf("%d", &m);
  printf("Enter matrix size n: ");
  scanf("%d", &n);
    
  for (i=0; i<m; i++)
    for (j=0; j<n; j++) A[i][j] = rand() % 100;
  
  transpose(m, n, A, B);
  
  printf("\nMatrix A:\n");
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  printf("\n");
    
  system("pause");
  return 0; 
}
