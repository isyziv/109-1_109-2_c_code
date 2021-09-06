/* This program implements the bubble sort algorithm.
   Assume the maximum number of elements is 100.
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int data[100];
  int n, i, j, inx, max;

  do
  {
    printf("**** Enter the number of elements: ");
    scanf("%d", &n);
  } while (n < 1 || n > 100);
  for (i = 0; i < n; i++)
  {
    printf("Enter sequence element data[%d]: ", i);
    scanf("%d", &data[i]);
  }
  printf("\nThe initial sequence:\n");
  for (i = 0; i < n; i++)
    printf("%4d", data[i]);
  printf("\n");

  // Program code for bubble sort.
  for (i = n; i > 1; i--)
  {
    inx = 0;
    for (j = 1; j < i; j++)
      if (data[inx] < data[j])
        inx = j;     /* Select the maximum element */
    max = data[inx]; /* Swap the selected and the maximum element */
    data[inx] = data[i - 1];
    data[i - 1] = max;
  }

  printf("\nThe sorted sequence:\n");
  for (i = 0; i < n; i++)
    printf("%4d", data[i]);
  printf("\n");

  system("pause");
  return 0;
}
