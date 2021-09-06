#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *a, i;

  a = malloc(sizeof(int) * 3);
  for (i=0; i<3; i++) a[i] = 10+i;

  printf("Address of a: X%X\n", &a);
  printf("Content of a: X%X\n", a);
  printf("Address of &a[0]: X%X\n", &a[0]);
  printf("Address of &a[1]: X%X\n", &a[1]);
  printf("Address of &a[2]: X%X\n", &a[2]);
  printf("Value of *a: %d\n", *a);
  printf("Value of a[0]: %d\n", a[0]);
  printf("Value of a[1]: %d\n", a[1]);
  printf("Value of a[2]: %d\n", a[2]);
  
  system("pause");
  return 0; 
}

