#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned long cnt=0;

// Compute determinant of a square matrix
float determinant(float **smatrix, int m) {
  float **cofactor;
  float d=0;
  int i, p, q;
  
  if (m == 1) {d = smatrix[0][0];} // Base case: when m is 1.
  else { // Recursive case: when m >1.
    // Dynamically, llocat memory for the cofactor, size is m-1 by m-1.    
    cofactor = (float **) malloc(sizeof(float *) * (m-1));
    for (i=0; i<m-1; i++) cofactor[i] = (float *) malloc(sizeof(float) * (m-1)); 
    
    for (i=0; i<m; i++) { // Expand the determinant along row 0.
      for (p=0; p<m-1; p++) { // The size of cofactor is m-1 by m-1.
        for (q=0; q<m-1; q++) { // The row and column indices of the cofacter are between 0 and m-2.
          // The elements on row 0 of smatrix are removed and 
          // the elements on column i of smatrix are removed.
          // Copy elements in row p+1 of smatrix to row p of the cofactor.
          // For the elements on the left-hand-side of column i, keep them in the same column.
          // For the elements on the right-hand-side of column i, move them one column to the left.
          if (q<i) cofactor[p][q] = smatrix[p+1][q]; 
          if (q>=i) cofactor[p][q] = smatrix[p+1][q+1];
        }
      }
      // Compute the determinant of smatrix according its definition.
      d = d + pow(-1, i % 2 ) * smatrix[0][i] * determinant(cofactor, m-1);
    }
    
    // Release memory allocated to the cofactor.
    for (i=0; i<m-1; i++) free(cofactor[i]); 
    free(cofactor);
  }
  cnt++;
  return d;
}

int main(void) {
  float **A;
  int i, j, n;
  clock_t start, finish;
  
  srand(time(NULL));
  
  // Enter the row and column size. 
  do {
    printf("Enter the row and column size of square matrix: ");
    scanf("%d", &n);
  } while (n<1 || n>15);
  
  // Dynamically allocate memory for sequre matrix A.
  // In the mean time, randomly generate the elements of square matrix A.  
  A = (float **) malloc(sizeof(float *) * n);
  for (i=0; i<n; i++) {
    A[i] = (float *) malloc(sizeof(float) * n);
    for (j=0; j<n; j++) A[i][j] = rand() % 100 / 100.0 + 1.0;
  }
  
  // Print square matrix A and the determinant of A.
  printf("Square matrix A (n=%d):\n\n", n);
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%4.2f ", A[i][j]);
    printf("\n");
  }
  
  start = clock();
  printf("\nDeterminant: %8.6f\n\n", determinant(A, n));
  finish = clock();
  
  printf("The number of function calls to determinant() is %d.\n", cnt);
  
  printf("The computing time of determinant is : %8.6f seconds\n\n",
         (double)(finish - start) / CLOCKS_PER_SEC);
  
  // Release memory allocated to square matrix A.
  for (i=0; i<n; i++) free(A[i]);
  free(A);
  
  system("pause");

  return  0;
}
