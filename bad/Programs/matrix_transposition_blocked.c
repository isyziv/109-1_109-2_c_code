#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Both A and B are nxn matrices, and block size b divides n.
// Set matrix B to be the transposition of matrix A using blocked transpostion algorithm.
void transpose_blocked(int n, int b, int A[100][100], int B[100][100]) {
  int i0, j0, i1, j1;
  
  for (i0=0; i0<n/b; i0++)
    for (j0=0; j0<n/b; j0++)
      for (i1=0; i1<b; i1++)
        for (j1=0; j1<b; j1++)
          B[j0*b+j1][i0*b+i1] = A[i0*b+i1][j0*b+j1];
}

int main(void) {
  int A[100][100], B[100][100];
  int n, b;
  int i, j;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);
  do {
    printf("Enter block size b (b is a factor of n): ");
    scanf("%d", &b);
  } while (n%b!=0);
    
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) A[i][j] = rand() % 100;
  
  transpose_blocked(n, b, A, B);
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  printf("\n");
    
  system("pause");
  return 0; 
}
