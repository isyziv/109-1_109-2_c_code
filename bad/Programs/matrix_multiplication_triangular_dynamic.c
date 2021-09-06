#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

int main(void) {
  int **A, **B, **C;
  int n;
  int i, j, k;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);
  
  A = (int **) malloc(sizeof(int*) * n);
  for (i=0; i<n; i++) A[i] = (int *) malloc(sizeof(int) * (i + 1));
  B = (int **) malloc(sizeof(int*) * n);
  for (i=0; i<n; i++) B[i] = (int *) malloc(sizeof(int) * (n - i));
  C = (int **) malloc(sizeof(int*) * n);
  for (i=0; i<n; i++) C[i] = (int *) malloc(sizeof(int) * n);
  
  for (i=0; i<n; i++)
    for (j=0; j<=i; j++) A[i][j] = rand() % 100 + 1;
    
  for (i=0; i<n; i++)
    for (j=0; j<n-i; j++) B[i][j] = rand() % 100 + 1;
    
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {
      C[i][j] = 0;
      for (k=0; k<=min(i,j); k++) C[i][j] += A[i][k] * B[k][j - k];
    }
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<=i; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("    ");
    for (j=0; j<n-i; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix C:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%6d ", C[i][j]);
    printf("\n");
  }
  
  printf("\n");
  
  // Deallocate memory space of matrices A, B, and C 
  for (i=0; i<n; i++) {free(A[i]); free(B[i]); free(C[i]);}
  free(A);
  free(B);
  free(C);
    
  system("pause");
  return 0; 
}
