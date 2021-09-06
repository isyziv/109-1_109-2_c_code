#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *a;

  a = malloc(sizeof(int));
  *a = 10;

  printf("Address of a: 0X%X\n", &a);
  printf("Content of a: 0X%X\n", a);
  printf("Value of *a: %d\n", *a);

  system("pause");
  return 0; 
}

