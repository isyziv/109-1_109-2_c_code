#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_double_list_char.h"

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
  List list;

  // Read file "longest_palindrome_in.txt"
  data = read_text("longest_palindrome_in.txt");
  length = strlen(data);
  
  // Remove space and punctuations and
  // convert all lower case characters to uppercase.
  count = 0;
  for (i=0; i<length; i++)
    if (isalpha(data[i])) data[count++] = toupper(data[i]);
  data[count] = '\0';
  
  // Create the  circular double-linked list.
  initial_list(&list);
  // Complete this program segment.
  
  // Check the number of nodes created.
  printf("The total length of the modified text is %d.\n", strlen(data));
  printf("The number of nodes in the circularly double-linked list is %d.\n", node_count);
  
  // Use double-linked list to perform palindrome test.
  isPalindrome = 1;
  // Complete this program segment.
  
  if (isPalindrome) printf(">>>> The modified string of the input file is a palindrome.\n");
  else printf(">>>> The modified string of input file is not a palindrome.\n\n");
  printf("\n*************************************************************************\n\n");
  
  free(data);  
  while (list!=NULL) delete_first(&list);
  system("pause");
  return 0;
}  
