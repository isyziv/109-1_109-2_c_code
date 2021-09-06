/* Sequential search. */

#include <stdio.h>

int main(void) {
  int i, found, key;
  int a[8] = {3, 8, 7, 2, 5, 4, 9, 2};

  printf("Enter a searched key: ");
  scanf("%d", &key);

  i = 0;
  found = 0;

  while (i<8 && !found) {
    if (a[i]==key) found = 1;
    else i++;
  }

  if (found) printf("Search succeeds. a[%d]=%d.\n", i, a[i]);
  else printf("Search fails. %d does not exist in the sequence.\n", key);

  system("pause");
  return 0;
}

