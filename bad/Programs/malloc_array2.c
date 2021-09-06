#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int **a, i, j;

  a = (int **) malloc(sizeof(int*) * 3);
  for (i=0; i<3; i++) (int *) a[i] = malloc(sizeof(int) * 4);
  
  for (i=0; i<3; i++)
    for (j=0; j<4; j++) a[i][j] = 100 + 10 * i + j;

  printf("Address of a: 0X%X\n", &a);
  printf("Content of a: 0X%X\n", a);

  for (i=0; i<3; i++)
    printf("Address of &a[%d]: 0X%X\n", i, &a[i]);

  for (i=0; i<3; i++)
    for (j=0; j<4; j++)
      printf("Address of &a[%d][%d]: 0X%X\n", i, j, &a[i][j]);
      
  for (i=0; i<3; i++)
    for (j=0; j<4; j++)
      printf("Value of a[%d][%d]: %d\n", i, j, a[i][j]);
  
  system("pause");
  return 0; 
}

