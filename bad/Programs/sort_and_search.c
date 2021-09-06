/* Sorting and searching functions.
*/
#include "sort_and_search.h"

void swap(int *ptr1, int *ptr2) {
	int tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

void bubble_sort(int *a, int n) {
  int i, j, inx;
  for (i=n; i>1; i--) {
	  inx = 0;
	  for (j=1; j<i; j++)
	    if (a[inx]<a[j]) inx = j; /* Select the maximum element */
    swap(&a[inx], &a[i-1]);
  }
}

int binary_search(int* a, int n, int key) {
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
