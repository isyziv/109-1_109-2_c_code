#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int **A, **B, **C;
  int m, n, p;
  int i, j, k;
  
  srand(time(NULL));
  
  printf("Enter matrix size m: ");
  scanf("%d", &m);
  printf("Enter matrix size n: ");
  scanf("%d", &n);
  printf("Enter matrix size p: ");
  scanf("%d", &p);
  
  // Allocate memory space for matrices A, B, and C
  A = (int **) malloc(sizeof(int*) * m);
  for (i=0; i<m; i++) A[i] = (int *) malloc(sizeof(int) * n);
  B = (int **) malloc(sizeof(int*) * n);
  for (i=0; i<n; i++) B[i] = (int *) malloc(sizeof(int) * p);
  C = (int **) malloc(sizeof(int*) * m);
  for (i=0; i<m; i++) C[i] = (int *) malloc(sizeof(int) * p);
  
  for (i=0; i<m; i++)
    for (j=0; j<n; j++) A[i][j] = rand() % 100;
    
  for (i=0; i<n; i++)
    for (j=0; j<p; j++) B[i][j] = rand() % 100;
    
  for (i=0; i<m; i++)
    for (j=0; j<p; j++) {
      C[i][j] = 0;
      for (k=0; k<n; k++) C[i][j] += A[i][k] * B[k][j];
    }
  
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
  
  // Deallocate memory space of matrices A, B, and C 
  for (i=0; i<m; i++) free(A[i]);
  free(A);
  for (i=0; i<n; i++) free(B[i]);
  free(B);
  for (i=0; i<m; i++) free(C[i]);
  free(C);
  
  system("pause");
  return 0; 
}
