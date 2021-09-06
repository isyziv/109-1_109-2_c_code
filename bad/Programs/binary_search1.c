#include <stdio.h>

void selectionSort(int* a, int n) {
  int i, j, index, temp;
  
  for (i = n; i > 0; i--) {
    index = 0;
    for (j = 0; j < i; j++) {
      if (a[index] < a[j]) index = j;
    }
    temp = a[index];
    a[index] = a[i-1];
    a[i-1] = temp;
  }
}

int binarySearch(int* a, int n, int key) {
  int found = 0, head = 0, tail = n - 1, mid;
  
  while (!found && head <= tail) {
    mid = head + (tail - head) / 2;
    if (a[mid] == key) found = 1;
    else if (a[mid] > key) tail = mid - 1;
    else head = mid + 1;
  }
  if (!found) mid = -1;  
  return mid;
}

int main(void) {
  int A[20] = { 6, 34, 21,  7, 43, 15,  9, 12, 20, 57,
               15, 42,  3, 35, 24, 14, 18, 20, 22, 36};
  int k, i, result;
  
  selectionSort(A, 20);
  printf("\nSorted array elements:\n");
  for (i=0; i < 20; i++) printf("    A[%d]=%d\n", i, A[i]);
  printf("\nEnetr a key: ");
  scanf("%d", &k);
  result = binarySearch(A, 20, k);
  if (result >= 0) printf("Search succeeds. A[%d]=%d.\n\n", result, k);
  else printf("Search fails. %d is not in array A.\n\n", k);
  
  system("pause");
}
