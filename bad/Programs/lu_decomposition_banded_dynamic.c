/* Banded LU-decomposition with dynamic arrays. */
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

int main(void) {
  float A[100][100], A1[100][100], L[100][100], U[100][100];
  float **AA, **LL, **UU;
  int n, r, s;
  int i, j, k, check;
  
  srand(time(NULL));
  
  printf("Enter matrix size n: ");
  scanf("%d", &n);
  printf("\nEnter the lower bandwidth of matrix A, r: ");
  scanf("%d", &r);  
  printf("\nEnter the upper bandwidth of matrix A, s: ");
  scanf("%d", &s);
  
  // Allocate dynamic memory for matrices AA, LL, and UU.
  AA = (float **) malloc(sizeof(float*) * n);
  for (i=0; i<n; i++) AA[i] = (float *) malloc(sizeof(float) * (min(n-1-i, s)+min(i, r)+1));
  LL = (float **) malloc(sizeof(float*) * n);
  // Since the bandwidth of the upper band of LL is zero, min(n-1-i, 0) is zero.
  for (i=0; i<n; i++) LL[i] = (float *) malloc(sizeof(float) * (min(i, r)+1)); 
  UU = (float **) malloc(sizeof(float*) * n);
  // Since the bandwidth of the lower band of UU is zero, min(i, 0) is zero.
  for (i=0; i<n; i++) UU[i] = (float *) malloc(sizeof(float) * (min(n-1-i, s)+1));
  
  // Initialize all elements of matrices A and A1 to zero.
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {A1[i][j]=0; A[i][j]=0;}
    
  // Get values for the elements of matrices A, A1, and AA.
  for (i=0; i<n; i++)
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) {
      A[i][j] = A1[i][j] = (rand() % 1000000 + 1) / 1000000.0;
      AA[i][j-max(0,i-r)] = A[i][j];
    }
  
  printf("\nMatrix A:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<max(0,i-r); j++) printf("         ");
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) printf("%8.4f ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix AA:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<max(0,i-r); j++) printf("         ");
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) printf("%8.4f ", AA[i][j-max(0,i-r)]);
    printf("\n");
  }
  
  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  
  // Calculate LU decomposition of A and AA.
  for (k=0; k<n; k++) {
    for (j=k; j<=min(n-1,k+s); j++) {
      U[k][j] = A[k][j];
      UU[k][j-k] = AA[k][j-max(0,k-r)];
    }
    for (i=k; i<=min(n-1,k+r); i++) {
      L[i][k] = A[i][k] / A[k][k];
      LL[i][k-max(0,i-r)] = AA[i][k-max(0,i-r)] / AA[k][k-max(0,k-r)];
    }
    for (i=k+1; i<=min(n-1,k+r); i++) {
      for (j=max(k+1,i-r); j<=min(n-1,min(i+s,k+s)); j++) {
        A[i][j] = A[i][j] - L[i][k] * U[k][j];
        AA[i][j-max(0,i-r)] = AA[i][j-max(0,i-r)] - LL[i][k-max(0,i-r)] * UU[k][j-k];
      }
    }
  }
  
  printf("\nMatrix L:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i-r; j++) printf("         ");
    for (j=max(0,i-r); j<=i; j++) printf("%8.4f ", L[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix LL:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i-r; j++) printf("         ");
    for (j=max(0,i-r); j<=i; j++) printf("%8.4f ", LL[i][j-max(0,i-r)]);
    printf("\n");
  }
  
  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  
  printf("\nMatrix U:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("         ");
    for (j=i; j<=min(n-1,i+s); j++) printf("%8.4f ", U[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix UU:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("         ");
    for (j=i; j<=min(n-1,i+s); j++) printf("%8.4f ", UU[i][j-i]);
    printf("\n");
  }
  
  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  
  check = 1;
  for (i=0; i<n; i++)
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) {
      A[i][j] = 0;
      for (k=max(0, max(i-r,j-s)); k<=min(n-1,min(i,j)); k++) A[i][j] += L[i][k] * U[k][j];
      check = check && (fabs(A[i][j]-A1[i][j])<0.0001);
    }
  
  if (check) printf("\n**** The LU-decomposition program with fixed-size arrays is correct.\n\n");
  else printf("\n**** The LU-decomposition program with fixed-size arrays is incorrect.\n\n");
  
  check = 1;
  for (i=0; i<n; i++)
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) {
      AA[i][j-max(0,i-r)] = 0;
      for (k=max(0, max(i-r,j-s)); k<=min(n-1,min(i,j)); k++) AA[i][j-max(0,i-r)] += LL[i][k-max(0,i-r)] * UU[k][j-k];
      check = check && (fabs(AA[i][j-max(0,i-r)]-A1[i][j])<0.0001);
    }
  
  if (check) printf("\n**** The LU-decomposition program with dynamic arrays is correct.\n\n");
  else printf("\n**** The LU-decomposition program with dynamic arrays is incorrect.\n\n");
    
  system("pause");
  return 0; 
}
