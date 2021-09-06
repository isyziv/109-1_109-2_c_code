#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_list_char.h"

char *read_text(const char *fname) {
  FILE *fPtr;
  char *text;
  unsigned long leng;
  
  fPtr = fopen(fname, "r");
  fseek(fPtr, 0, SEEK_END);
  leng = ftell(fPtr);
  fseek(fPtr, 0, SEEK_SET);
  text = (char *) malloc((leng + 1) * sizeof(char));
  fread(text, 1, leng, fPtr);  
  fclose(fPtr);
  text[leng] = '\0';
  return text;
}

int main(void) {
  char *data, *ptr;
  unsigned long i, length, count, node_count, isPalindrome;
  DList list;

  // Read file "aVeryLongText.txt"
  data = read_text("longest_palindrome_in.txt");
  length = strlen(data);
  
  // Remove space and punctuations and
  // convert all lower case characters to uppercase.
  count = 0;
  for (i=0; i<length; i++)
    if (isalpha(data[i])) data[count++] = toupper(data[i]);
  data[count] = '\0';
  
  // Create the double-linked list.
  initial_list(&list);
  ptr = data;
  node_count = 0;
  while (*ptr!='\0') {
    insert(&list, *ptr);
    ptr++;
    node_count++;
  }  
  
  // Check the number of nodes created.
  printf("The total length of the modified text is %d.\n", strlen(data));
  printf("The number of nodes in the double-linked list is %d.\n", node_count);
  
  // Use double-linked list to perform palindrome test.
  
  isPalindrome = 1;
  while (isPalindrome && list.first!=NULL && list.first!=list.last) {
    if (list.first->elem!=list.last->elem) isPalindrome = 0;
    else {
      delete_first(&list);
      delete_last(&list);
    }
  }
  
  if (isPalindrome) printf(">>>> The modified string of the input file is a palindrome.\n");
  else printf(">>>> The modified string of input file is not a palindrome.\n\n");
  printf("\n*************************************************************************\n\n");
  
  free(data);  
  while (list.first!=NULL) delete_first(&list);
  system("pause");
  return 0;
}  
