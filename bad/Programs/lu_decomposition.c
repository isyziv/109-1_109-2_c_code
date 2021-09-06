/* LU-decomposition. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: nxn matrix,
   L: nxn lower triangular matrix,
   U: nxn upper triangular matrix.
   Compute A=LU.
*/
void LU_decompose(int n, float A[100][100], float L[100][100], float U[100][100]) {
  int i, j, k;
    
  for (k=0; k<n; k++) {
    for (j=k; j<n; j++) U[k][j] = A[k][j];
    for (i=k; i<n; i++) L[i][k] = A[i][k] / A[k][k];
    for (i=k+1; i<n; i++)
      for (j=k+1; j<n; j++) A[i][j] = A[i][j] - L[i][k] * U[k][j];
  }
}

int main(void) {
  float A[100][100], A1[100][100], L[100][100], U[100][100];
  int n, i, j, k, check;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);
    
  // Get values for the elements of matrix A.
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {A[i][j] = (rand() % 1000000 + 1) / 1000000.0; A1[i][j] = A[i][j];}
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%8.4f ", A[i][j]);
    printf("\n");
  }
  
  LU_decompose(n, A, L, U);
  
  printf("\nMatrix L:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<=i; j++) printf("%8.4f ", L[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix U:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("         ");
    for (j=i; j<n; j++) printf("%8.4f ", U[i][j]);
    printf("\n");
  }
  
  check = 1;
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {
      A[i][j] = 0;
      for (k=0; k<=min(i,j); k++) A[i][j] += L[i][k] * U[k][j];
      check = check && (fabs(A[i][j]-A1[i][j])<0.0001);
    }
  
  if (check) printf("\nThe LU-decomposition program is correct.\n\n");
  else printf("\nThe LU-decomposition program is incorrect.\n\n");
    
  system("pause");
  return 0; 
}
