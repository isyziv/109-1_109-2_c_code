/* This program implements the binary search algorithm of all matched elements.
*/

#include <stdio.h>

int main( ) { 
	int a[100];
	int mark[100];
	int n, key, found, i, j;
	
	// Enter the value of variable n to denote the length of data sequence.
	printf("Enter the length of array a (between 1 and 100): ");
  scanf("%d", &n);
  
  // Enter initial values of n data elements.
  printf("\n");
  for (i=0; i<n; i++) {
  	printf("Enter the value of element a[%d]: ", i);
    scanf("%d", &a[i]);
  }
  
  // Enter the value of searched key.
  printf("\nEnter the value of searched key: ");
  scanf("%d", &key);
  
  //Print the values of all n elements with five elements in a line.
  printf("\nThe data sequence is:\n");
  j = 0;
  for (i=0; i<n; i++) {
    printf("a[%2d]=%2d  ", i, a[i]);
    j++;
    if (j==5) {
      printf("\n");
      j = 0;
    }
  }
  printf("\n");
  
  // Search all elements of the value of key.
  found = 0;
  for (i=0; i<n; i++) {
    mark[i] = 0;
    if (a[i]==key) {
      mark[i] = 1;
      found = 1;
    }
  }
  
  // Print the indices and values of all matched elements.
  if (found) {
    printf("\nSearch succeeds. The matched are:\n");
    j = 0;
    for (i=0; i<n; i++) {
      if (mark[i]==1) {
        printf("a[%2d]=%2d  ", i, a[i]);
        j++;
        if (j==5) {
          printf("\n");
          j = 0;
        }
      }
    }
    printf("\n\n");
  }
  else printf("\nSearch fails. %d is not an element of the sequence.\n\n", key);
  
  system("pause");
  return 0;
}
