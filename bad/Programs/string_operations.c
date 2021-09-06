#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
  char *data, *ptr, *ptr1;
  char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
  char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
  char vowels[] = "AEIOU";
  int word_count[7], vowel_count[5], length;
  int i, isPalindrome;
  
  // Read file "aVeryLongText.txt"
  data = read_text("aVeryLongText.txt");
  
  // Convert all lower case characters to uppercase and output the first 500 characters.
  ptr = (char *) strpbrk(data, lowercase);
  while (ptr!=NULL) {
    *ptr = *ptr - 32; // 'a'-'A' is 32
    ptr = (char *) strpbrk(ptr, lowercase);
  }
  ptr = (char *) malloc(501);
  strncpy(ptr, data, 500);
  ptr[500] = '\0';
  printf(">>>> The first 500 characters of the input text in uppercase:\n\n%s\n", ptr);
  free(ptr);
  printf("\n*************************************************************************\n\n");
  
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
  ptr = (char *) malloc(501);
  strncpy(ptr, data, 500);
  ptr[500] = '\0';
  printf(">>>> The first 500 characters of the input text in uppercase, letters only:\n\n%s\n", ptr);
  free(ptr);
  printf("\n*************************************************************************\n\n"); 
  
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
  
  isPalindrome = 1;
  length = strlen(data);
  for (i=0; i<=length/2; ++i) {
    if (data[i]!=data[length-1-i]) isPalindrome = 0;
  }
  if (isPalindrome) printf(">>>> The modified string of the input file is a palindrome.\n");
  else printf(">>>> The modified string of input file is not a palindrome.\n\n");
  printf("\n*************************************************************************\n\n");
  
  free(data);
  system("pause");
  return 0;
}  
