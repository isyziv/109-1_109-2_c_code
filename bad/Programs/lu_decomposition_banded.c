/* Banded LU-decomposition. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int max(int x, int y) {
  if (x>y) return x;
  else return y;
}

int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: nxn matrix,
   r: the lower bandwidth of matrix A,
   s: the upper bandwidth of matrix A,
   Compute A=LU using banded LU decomposition.
*/
void lu_decompose_banded(int n, int r, int s, float A[100][100], float L[100][100], float U[100][100]) {
  int i, j, k;
    
  for (k=0; k<n; k++) {
    for (j=k; j<=min(n-1,k+s); j++) U[k][j] = A[k][j];
    for (i=k; i<=min(n-1,k+r); i++) L[i][k] = A[i][k] / A[k][k];
    for (i=k+1; i<=min(n-1,k+r); i++)
      for (j=max(k+1,i-r); j<=min(n-1,min(i+s,k+s)); j++) A[i][j] = A[i][j] - L[i][k] * U[k][j];
  }
}

int main(void) {
  float A[100][100], A1[100][100], L[100][100], U[100][100];
  int n, r, s;
  int i, j, k, check;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);
  printf("\nEnter the lower bandwidth of matrix A, r: ");
  scanf("%d", &r);  
  printf("\nEnter the upper bandwidth of matrix A, s: ");
  scanf("%d", &s);  
  
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {A1[i][j]=0; A[i][j]=0;}
    
  // Get values for the elements of matrix A.
  for (i=0; i<n; i++)
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) {A[i][j] = A1[i][j] = (rand() % 1000000 + 1) / 1000000.0;}
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<max(0,i-r); j++) printf("         ");
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) printf("%8.4f ", A[i][j]);
    printf("\n");
  }
  
  // Decompose A into matrices L and U.
  lu_decompose_banded(n, r, s, A, L, U);
  
  printf("\nMatrix L:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i-r; j++) printf("         ");
    for (j=max(0,i-r); j<=i; j++) printf("%8.4f ", L[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix U:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("         ");
    for (j=i; j<=min(n-1,i+s); j++) printf("%8.4f ", U[i][j]);
    printf("\n");
  }
  
  check = 1;
  for (i=0; i<n; i++)
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) {
      A[i][j] = 0;
      for (k=max(0, max(i-r,j-s)); k<=min(n-1,min(i,j)); k++) A[i][j] += L[i][k] * U[k][j];
      check = check && (fabs(A[i][j]-A1[i][j])<0.0001);
    }
  
  if (check) printf("\nThe LU-decomposition program is correct.\n\n");
  else printf("\nThe LU-decomposition program is incorrect.\n\n");
    
  system("pause");
  return 0; 
}
