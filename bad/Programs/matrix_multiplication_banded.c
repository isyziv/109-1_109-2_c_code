/* Banded matrix multiplication. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int x, int y) {
  if (x>y) return x;
  else return y;
}

int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: nxn matrix,
   B: nxn matrix,
   C: nxn matrix,
   ra: the lower bandwidth of matrix A,
   rb: the upper bandwidth of matrix A,
   sa: the lower bandwidth of matrix A,
   sb: the upper bandwidth of matrix A,
   Compute C=AB using banded matrix multiplication algorithm.
*/
void matrix_product_banded(int n, int ra, int rb, int sa, int sb,
                           int A[100][100], int B[100][100], int C[100][100]) {
  int i, j, k;
    
  for (i=0; i<n; i++)
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) {
      C[i][j] = 0;
      for (k=max(0, max(i-ra,j-sb)); k<=min(n-1,min(i+sa,j+rb)); k++) C[i][j] += A[i][k] * B[k][j];
    }
}

int main(void) {
  int A[100][100], B[100][100], C[100][100], C1[100][100];
  int n, ra, sa, rb, sb;
  int i, j, k;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);  
  printf("\nEnter the lower bandwidth of matrix A, ra: ");
  scanf("%d", &ra);  
  printf("\nEnter the upper bandwidth of matrix A, sa: ");
  scanf("%d", &sa);  
  printf("\nEnter the lower bandwidth of matrix B, rb: ");
  scanf("%d", &rb);  
  printf("\nEnter the upper bandwidth of matrix B, sb: ");
  scanf("%d", &sb);
    
  // Get values for the elements of matrix A.
  for (i=0; i<n; i++)
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++) A[i][j] = rand() % 100 + 1;
    
  // Get values for the elements of matrix B.
  for (i=0; i<n; i++)
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) B[i][j] = rand() % 100 + 1;
    
  // Compute banded matrix multiplication.
  matrix_product_banded(n, ra, rb, sa, sb, A, B, C);
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-ra); j++) printf("   ");
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++) printf("%2d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-rb); j++) printf("   ");
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) printf("%2d ", B[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix C:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-ra-rb); j++) printf("      ");
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) printf("%5d ", C[i][j]);
    printf("\n");
  }
  
  printf("\n");
    
  system("pause");
  return 0; 
}
