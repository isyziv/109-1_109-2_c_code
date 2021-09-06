#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exchange the values of x and y.
void swap(int *x, int *y) {
  int temp;
  
  temp = *x;
  *x = *y;
  *y = temp;
}

// A is an mxn matrix and B is an nxm matrix.
// Set matrix A to be the transposition of matrix A itself.
void transpose_in_place(int n, int A[100][100]) {
  int i, j;
  
  for (i=0; i<n; i++)
    for (j=0; j<i; j++) 
      swap(&A[i][j], &A[j][i]);
}

int main(void) {
  int A[100][100];
  int n;
  int i, j;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);
    
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) A[i][j] = rand() % 100;
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  transpose_in_place(n, A);
  
  printf("\nMatrix A after in-place transposition:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\n");  
    
  system("pause");
  return 0; 
}
