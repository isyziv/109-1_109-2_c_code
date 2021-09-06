#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A: mxn matrix,
   B: nxp matrix,
   C: mxp matrix.
   Compute C=AB using regular matrix multiplication.
*/
void matrix_product(int n, int A[100][100], int B[100][100], int C[100][100]) {
  int i, j, k;
    
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) 
      for (k=0; k<n; k++) C[i][j] += A[i][k] * B[k][j];
}

/* A: nxn matrix,
   B: nxn matrix,
   C: nxn matrix.
   b: block size where b divides n; n/b the number of blocks.
   Compute C=AB using blocked matrix multiplication algorithm.
*/
void matrix_product_blocked(int n, int b, int A[100][100], int B[100][100], int C[100][100]) {
  int i0, j0, k0, i1, j1, k1;
    
  for (i0=0; i0<n/b; i0++)
    for (j0=0; j0<n/b; j0++) 
      for (k0=0; k0<n/b; k0++)
        for (i1=0; i1<b; i1++)
          for (j1=0; j1<b; j1++)
            for (k1=0; k1<b; k1++) C[i0*b+i1][j0*b+j1] += A[i0*b+i1][k0*b+k1] * B[k0*b+k1][j0*b+j1];
}

int main(void) {
  int A[100][100], B[100][100], C[100][100], C1[100][100];
  int n, b;
  int i, j, k;
  int check = 1;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);
  do {
    printf("Enter block size b (b is a factor of n): ");
    scanf("%d", &b);
  } while (n%b!=0);
    
  // Initialize matrices A, B, C, and C1.  
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {
      A[i][j] = rand() % 100;
      B[i][j] = rand() % 100;
      C[i][j] = 0;
      C1[i][j] = 0;
  }
    
  // Using blocked matrix multiplication.
  matrix_product_blocked(n, b, A, B, C);
    
  // Using regular matrix multiplication.
  matrix_product(n, A, B, C1);
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%2d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%2d ", B[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix C:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%5d ", C[i][j]);
    printf("\n");
  }
  
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) check = check && (C[i][j]==C1[i][j]);
    
  if (check) printf("\n**** The result of blocked matrix multiplication is correct.\n\n");
  else printf("\n**** The result of blocked matrix multiplication is incorrect.\n\n");
    
  system("pause");
  return 0; 
}
