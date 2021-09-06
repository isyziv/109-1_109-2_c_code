#include <stdio.h>

void read_sequence(int *a, int n) {
  int i;
  for (i=0; i<n; i++) {
    printf("Enter the value element %d: ", i);
    scanf("%d", &a[i]);
  }
}

void compare_swap (int *a1, int *a2) {
  int temp;
  if (*a1>*a2) {
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
  }
}

void sort_sequence(int *a, int n) {
  int i, j;
  for (i=n-1; i>0; i--)
    for (j=1; j<=i; j++)
      compare_swap(&a[j-1], &a[j]);
}


void print_sequence(int *a, int n) {
  int i;
  printf("\nThe sorted sequence is:\n");
  for (i=0; i<n; i++) printf("%d  ", a[i]);
  printf("\n");
}

int main (void) {
  int data[10];

  read_sequence(data, 10);
  sort_sequence(data, 10);
  print_sequence(data, 10);

  system("pause");
  return 0;
}

