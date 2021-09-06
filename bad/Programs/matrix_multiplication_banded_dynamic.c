/* Banded matrix multiplication with dynamic arrays. */
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

int main(void) {
  int A[100][100], B[100][100], C[100][100];
  int **AA, **BB, **CC;
  int n, ra, sa, rb, sb;
  int i, j, k;
  int check;
  
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
  
  // Allocate dynamic memory for matrices AA, BB, and CC.
  AA = (int **) malloc(sizeof(int*) * n);
  for (i=0; i<n; i++) AA[i] = (int *) malloc(sizeof(int) * (min(i, ra)+1+min(n-1-i, sa)));
  BB = (int **) malloc(sizeof(int*) * n);
  for (i=0; i<n; i++) BB[i] = (int *) malloc(sizeof(int) * (min(i, rb)+1+min(n-1-i, sb)));
  CC = (int **) malloc(sizeof(int*) * n);
  for (i=0; i<n; i++) CC[i] = (int *) malloc(sizeof(int) * (min(i, ra+rb)+1+min(n-1-i, sa+sb)));
  
  // Get values for the elements of matrices A and AA.
  for (i=0; i<n; i++)
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++) {A[i][j] = rand() % 100 + 1; AA[i][j-max(0,i-ra)] = A[i][j];}
      
  // Get values for the elements of matrices B and BB.
  for (i=0; i<n; i++)
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) {B[i][j] = rand() % 100 + 1; BB[i][j-max(0,i-rb)] = B[i][j];}
  
  // Compute matrix multiplication with fixed size arrays and dynamic arrays.
  // Check correctness of the results of each element of matrix C and CC.
  check = 1;
  for (i=0; i<n; i++)
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) {
      C[i][j] = 0;
      CC[i][j-max(0,i-ra-rb)] = 0; 
      for (k=max(0, max(i-ra,j-sb)); k<=min(n-1,min(i+sa,j+rb)); k++) {
        C[i][j] += A[i][k] * B[k][j];
        CC[i][j-max(0,i-ra-rb)] += AA[i][k-max(0,i-ra)] * BB[k][j-max(0,k-rb)];
      } 
      check = check && (C[i][j]==CC[i][j-max(0,i-ra-rb)]);
    }
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-ra); j++) printf("    ");
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix AA:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-ra); j++) printf("    ");
    for (j=max(0,i-ra); j<=min(n-1,i+sa); j++) printf("%3d ", AA[i][j-max(0,i-ra)]);
    printf("\n");
  }
  
  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  
  printf("\nMatrix B:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-rb); j++) printf("    ");
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix BB:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-rb); j++) printf("    ");
    for (j=max(0,i-rb); j<=min(n-1,i+sb); j++) printf("%3d ", BB[i][j-max(0,i-rb)]);
    printf("\n");
  }
  
  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  
  printf("\nMatrix C:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-ra-rb); j++) printf("       ");
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) printf("%6d ", C[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix CC:\n");
  for (i=0; i<n; i++) {
    printf("    ");
    for (j=0; j<max(0,i-ra-rb); j++) printf("       ");
    for (j=max(0,i-ra-rb); j<=min(n-1,i+sa+sb); j++) printf("%6d ", CC[i][j-max(0,i-ra-rb)]);
    printf("\n");
  }
  
  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  
  if (check) printf("\n**** The banded matrix mutliplication program with dynamic array is correct.\n\n");
  else printf("\n**** The banded matrix mutliplication program with dynamic array is incorrect.\n\n");
  
  // Deallocate memory space of matrices A, B, and C 
  for (i=0; i<n; i++) {free(AA[i]); free(BB[i]); free(CC[i]);}
  free(AA);
  free(BB);
  free(CC);
      
  system("pause");
  return 0; 
}
