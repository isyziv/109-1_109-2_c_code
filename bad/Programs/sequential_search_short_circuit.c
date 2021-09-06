/* Sequential search with short circuit evaluation. */

#include <stdio.h>

int main(void) {
  int i, key;
  int a[8] = {3, 8, 7, 2, 5, 4, 9, 2};
  
  printf("Enter a searched key: ");
  scanf("%d", &key);
  
  i = 0;

  while (i<8 && a[i]!=key) i++;

  if (i<8) printf("Search succeeds. a[%d]=%d.\n", i, a[i]);
  else printf("Search fails. %d does not exist in the sequence.\n", key);
  
  system("pause");
  return 0;
}
