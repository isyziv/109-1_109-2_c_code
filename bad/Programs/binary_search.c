/* This program implements the binary search algorithm.
*/

#include <stdio.h>

int main( ) { 
	int data[100];
	int n, i, low, high, mid, found, key;
	
	do {
	  printf("**** Enter the number of elements: ");
	  scanf("%d", &n);
  } while (n<1 || n>100);
  for (i=0; i<n; i++) {
    printf("Enter sorted sequence element data[%d]: ", i);
    scanf("%d", &data[i]); 
  }
  printf("\nThe initial sequence:\n");
  for (i=0; i<n; i++) printf("%4d", data[i]);
  printf("\n");
  
	printf("**** Enter a searched key: ");
  scanf("%d", &key);
  
  // Program code for binary search.
  low = 0;
  high = n-1;
  found = 0;  
  while (!found && low<=high) {
    mid = low + (high - low) / 2;
    if (data[mid]==key) found = 1;
    else if (data[mid]>key) high =  mid -1;
    else low =  mid + 1;
  }
  
  if (found) printf("Search succeeds. data[%d]=%d.\n", mid, data[mid]);
  else printf("Search fails. %d does not exist in the sequence.\n", key);
  
  system("pause");
  return 0;
}
