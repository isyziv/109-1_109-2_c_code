#include <stdio.h>
#include <stdlib.h>
#include "sort_and_search.h"

int main( ) { 
	int data[100];
	int n, key, result, i;
	
	do {
	  printf("**** Enter the number of elements: ");
	  scanf("%d", &n);
  } while (n<1 || n>100);
  for (i=0; i<n; i++) {
    printf("Enter sequence element data[%d]: ", i);
    scanf("%d", &data[i]); 
  }
  printf("\nThe initial sequence:\n");
  for (i=0; i<n; i++) printf("%4d", data[i]);
  printf("\n\n");
  
	printf("**** Enter a searched key: ");
  scanf("%d", &key);
  
  bubble_sort(data, n);
  result = binary_search(data, n, key);
  
  if (result>=0) printf("\nSearch succeeds. Key %d is an element of the sequence.\n", key);
  else printf("\nSearch fails. Key %d is not an element of the sequence\n", key);
  
  system("pause");
  return 0;
}
