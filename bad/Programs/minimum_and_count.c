/* This program reads the value (between 1 and 20) of variable n and
   n elements of a sequence. Then, it outputs the minimum element
   and the count of element with the minimum value.
*/

#include <stdio.h>

int main(void) {
  int a[20];
  int n, min, count, i;
 
  do {
    printf("Enter the number of elements: ");
    scanf("%d", &n);
  } while (n<1 || n>20);
  printf("\n");
  
  for (i=0; i<n; i++) {
    printf("Enter element a[%d]: ", i);
    scanf("%d", &a[i]);
  }
  printf("\n");
  
  min = a[0];
  count = 1;
  for (i=1; i<n; i++) {
    if (a[i]<min) {
      min = a[i];
      count = 1;
    }
    else if (a[i]==min) {
      count++;
    }
  }  
  printf("There is (are) %d element(s) with minimum value %d.\n\n", count, min);
  
  system("pause");
  return 0; 
}
