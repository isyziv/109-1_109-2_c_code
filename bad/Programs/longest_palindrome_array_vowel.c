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
  FILE *fPtr;
  char *data, *ptr, *ptr1;
  char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
  char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
  char vowels[] = "AEIOU";
  unsigned int word_count[7], vowel_count[5], length;
  int i;
  
  // Read file "aVeryLongText.txt"  
  fPtr = fopen("longest_palindrome_in.txt", "r");
  fseek(fPtr, 0, SEEK_END);
  length = ftell(fPtr);
  fseek(fPtr, 0, SEEK_SET);
  data = (char *) malloc((length + 1) * sizeof(char));
  fread(data, 1, length, fPtr);  
  fclose(fPtr);
  data[length] = '\0';
  
  // Convert all lower case characters to uppercase and output the first 500 characters.
  ptr = (char *) strpbrk(data, lowercase);
  while (ptr!=NULL) {
    *ptr = *ptr - 32; // 'a'-'A' is 32
    ptr = (char *) strpbrk(ptr, lowercase);
  }
  
  // Count the number of words with length 1 to 6 and over.
  for (i=0; i<7; i++) word_count[i] = 0;
  ptr = (char *) strpbrk(data, uppercase);
  while (ptr!=NULL) {
    length = strspn(ptr, uppercase);
    if (length<7) ++word_count[length-1];
    else ++word_count[6];
    ptr = (char *) strpbrk(ptr+length, uppercase);
  }
  printf(">>>> Word counts with length 1 to 6 and over:\n\n");
  for (i=0; i<6; i++) printf("The number of words with length %d: %d\n", i+1, word_count[i]);
  printf("The number of words with length greater than 6: %d\n", word_count[6]);
  printf("\n*************************************************************************\n\n");
  
  // Remove space and punctuations.
  ptr1 = data;
  ptr = (char *) strpbrk(data, uppercase);
  while (ptr!=NULL) {
    *ptr1 = *ptr;
    ptr1++;
    ptr = (char *) strpbrk(ptr+1, uppercase);
  }
  *ptr1 = '\0';
  
  // Count the occurences of  'A', 'E', 'I', 'O', 'U'.
  ptr = (char *) strpbrk(data, vowels);
  for (i=0; i<5; i++) vowel_count[i] = 0;
  while (ptr!=NULL) {
    switch (*ptr) {
      case 'A': {++vowel_count[0]; break;}
      case 'E': {++vowel_count[1]; break;}
      case 'I': {++vowel_count[2]; break;}
      case 'O': {++vowel_count[3]; break;}
      case 'U': {++vowel_count[4]; break;}
    }
    ptr = (char *) strpbrk(ptr+1, vowels);
  }
  printf(">>>> Vowel counts:\n\n");
  for (i=0; i<5; i++) printf("The number of vowel \'%c\': %d\n", vowels[i], vowel_count[i]);
  printf("\n*************************************************************************\n\n");
  
  if (isPalindrome(data)) printf(">>>> The modified string of the input file is a palindrome.\n");
  else printf(">>>> The modified string of input file is not a palindrome.\n\n");
  printf("\n*************************************************************************\n\n");
  
  free(data);
  system("pause");
  return 0;
}  
