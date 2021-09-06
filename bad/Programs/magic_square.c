#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(void) {
  int **square;
  int n, i, j;
  int value = 1, row, col;
  int total, sum, valid = 1;
  
  do {
    printf("Enter the size of the magic square: ");
    scanf("%d", &n);
  } while (n<3 || n >20 || n%2==0);
  
  square = (int **) malloc(sizeof(int *) * n);
  for (i=0; i<n; i++) {
    square[i] = (int *) malloc(sizeof(int) * n);
    assert(square[i]!=NULL);
    for (j=0; j<n; j++) square[i][j] = 0;
  }
  
  // Place 1 at the center of row 0.
  row = 0;
  col = n / 2;
  square[row][col] = value++;

  while (value<=n*n) {
    if (square[(row-1+n)%n][(col-1+n)%n]==0) {
      // Fill in the value on the upper-left.
      square[(row-1+n)%n][(col-1+n)%n] = value++;
      row = (row - 1 + n) % n;
      col = (col - 1 + n) % n;
    }
    else {
      // Fill in the value below.
      square[(row+1)%n][col] = value++;
      row = (row + 1) % n;
    }
  }

  printf("\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%4d", square[i][j]);
    printf("\n");
  }
  printf("\n");
  
  total = (1 + n * n) * n / 2;
  for (i=0; i<n; i++) {
    sum = 0;
    for (j=0; j<n; j++) sum += square[i][j];
    if (sum!=total) {
      printf("The magic square is incorrect at row %d.\n\n", i);
      valid = 0;
      break;
    }
    printf("Horizontal row %d check pass.\n", i);
  }
  
  for (i=0; i<n; i++) {
    sum = 0;
    for (j=0; j<n; j++) sum += square[j][i];
    if (sum!=total) {
      printf("The magic square is incorrect at column %d.\n\n", i);
      valid = 0;
      break;
    }
    printf("Vertical column %d check pass.\n", i);
  }
   
  sum = 0;
  for (i=0; i<n; i++) sum += square[i][i];
  if (sum!=total) {
    printf("The magic square is incorrect at the diagonal.\n\n");
    valid = 0;
  }
  else printf("Diagonal check pass.\n");
   
  sum = 0;
  for (i=0; i<n; i++) sum += square[i][n-1-i];
  if (sum!=total) {
    printf("The magic square is incorrect at the anti-diagonal.\n\n");
    valid = 0;
  }
  else printf("Anti-diagonal check pass.\n");
  
  if (valid) printf("\nThe magic square is correct. The total sum is %d.\n\n", total);
  
  system("pause");
  return 0; 
}
