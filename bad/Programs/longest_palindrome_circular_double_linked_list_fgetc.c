#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "circular_double_list_char.h"

int main(void) {
  char letter;
  FILE *fPtr;
  int node_count=0, isPalindrome;
  List list;
  
  initial_list(&list);

  // Read file "aVeryLongText.txt". Insert letters to circular double-linked list.
  fPtr = fopen("aVeryLongText.txt", "r");
  while (!feof(fPtr)) {
    letter = fgetc(fPtr);
    if (isalpha(letter)) {
      insert(&list, tolower(letter));
      node_count++;
    }
  }
  fclose(fPtr);
  
  // Check the number of nodes created.
  printf("The number of nodes in the circular double-linked list is %d.\n", node_count);
  
  // Use double-linked list to perform palindrome test.
  
  isPalindrome = 1;
  while (isPalindrome && list!=NULL && list->prev!=list) {
    if (list->elem!=list->prev->elem) isPalindrome = 0;
    if (list->prev!=list) {
      delete_first(&list);
      delete_last(&list);
    }
  }
  if (isPalindrome) printf(">>>> The modified string of the input file is a palindrome.\n");
  else printf(">>>> The modified string of input file is not a palindrome.\n\n");
  printf("\n*************************************************************************\n\n");
   
  while (list!=NULL) delete_first(&list);
  system("pause");
  return 0;
}
