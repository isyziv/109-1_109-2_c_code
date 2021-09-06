#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(char* s) {

  int h = 0, t = strlen(s) - 1;
  
  while (h<t) if (s[h++]!=s[t--]) return 0;
  return 1;
}

int main(void) {
  char *data, *charPtr;
  FILE *fPtr;
  unsigned long leng, count, i;
  char one_chars[2];
  unsigned int charCount[4] = {0, 0, 0, 0}, totalCount = 0;
  
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
  
  charPtr = data;
  one_chars[1] = '\0';
  while (charPtr[0]!='\0') {
    one_chars[0] = charPtr[0];
    count = strspn(charPtr, one_chars);
    count = count < 4 ? count : 4;
    charPtr = charPtr + count;
    ++charCount[count-1];
  }
  
  printf("Number of one character: %d\n", charCount[0]);
  printf("Number of two contiguous characters: %d\n", charCount[1]);
  printf("Number of three contiguous characters: %d\n", charCount[2]);
  printf("Number of four or more contiguous characters: %d\n", charCount[3]);
  totalCount = charCount[0]+charCount[1]*2+charCount[2]*3+charCount[3]*4;
  printf("Total characater counts: %d\n\n", totalCount);
  
  if (isPalindrome(data)) {
    printf("Yes, it is a palindrome.\n\n");
  }
  else printf("No, it is not a palindrome.\n\n");
    
  system("pause");
  return 0;
}  
