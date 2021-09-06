#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isPalindrome(char * s) {

  int h = 0, t = strlen(s) - 1;
  
  while (h<t) if (s[h++]!=s[t--]) return 0;
  return 1;
}

int main(void) {
  char *data;
  FILE *fPtr;
  unsigned long leng, count, i;
  
  fPtr = fopen("longest_palindrome_in.txt", "r");
  fseek(fPtr, 0, SEEK_END);
  leng = ftell(fPtr);
  fseek(fPtr, 0, SEEK_SET);
  data = (char *) malloc((leng + 1) * sizeof(char));
  fread(data, 1, leng, fPtr);  
  fclose(fPtr);
  data[leng] = '\0';
  
  count = 0;
  for (i=0; i<leng; i++)
    if (isalpha(data[i])) data[count++] = toupper(data[i]);
  data[count] = '\0';
  
  fPtr = fopen("longest_palindrome_out.txt", "w");
  fwrite(data, 1, count, fPtr);
  fclose(fPtr);
  
  printf("The longest palindrome has %d characters.\n\n", count);
  
  if (isPalindrome(data)) {
    printf("Yes, it is a palindrome.\n\n");
  }
  else printf("\n\nNo, it is not a palindrome.\n\n");
    
  system("pause");
  return 0;
}  
