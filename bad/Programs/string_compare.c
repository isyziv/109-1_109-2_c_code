/* Functions for comparing two strings.
	
   Compares two strings str1 and str2.
   Returns 0 if str1 and str2 are same strings; 
   returns a negative number, if str1 is lexical graphically less than str2;
   returns a positive number, if str1 is lexical graphically greater than str2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Iterative version
int strcmp_ite(const char *str1, const char *str2) {
  int result = 0;
  int i = 0;

  i = 0;
  while (!result && str1[i]!='\0' && str2[i]!='\0') {
    if (str1[i]>str2[i]) result = 1;
    else if (str1[i]<str2[i]) result = -1;
    i++;
  } 
  if (!result && str1[i]!='\0') result = 1;
  else if (!result && str2[i]!='\0') result = -1;
  return result;
}

//Recirsive version
int strcmp_rec(const char *str1, const char *str2) {
  if (*str1==*str2 && *str1!='\0') return strcmp_rec(str1+1, str2+1);
  else if (*str1<*str2) return -1;
  else if (*str1>*str2) return 1;
  else return 0;
}

// The testing code includes the library version, the iterative vesion, 
// and the recursive version.
int main(void) {

  printf("The library version:\n\n"); 
  printf("strcmp(\"book\", \"desk\") returns %d\n", strcmp("book", "desk"));
  printf("strcmp(\"abc\", \"abc\") returns %d\n", strcmp("abc", "abc"));
  printf("strcmp(\"abc\", \"abcde\") returns %d\n", strcmp("abc", "abcde"));
  printf("strcmp(\"xyz\", \"XYZ\") returns %d\n", strcmp("xyz", "XYZ"));
  printf("strcmp(\"abc\", \"XYZ\") returns %d\n", strcmp("abc", "XYZ"));
  printf("strcmp(\"abc\", \"xYZ\") returns %d\n", strcmp("abc", "xYZ"));
  printf("\n------------------------------------------------------\n");

  printf("The iterative version:\n\n"); 
  printf("strcmp_ite(\"book\", \"desk\") returns %d\n", strcmp_ite("book", "desk"));
  printf("strcmp_ite(\"abc\", \"abc\") returns %d\n", strcmp_ite("abc", "abc"));
  printf("strcmp_ite(\"abc\", \"abcde\") returns %d\n", strcmp_ite("abc", "abcde"));
  printf("strcmp_ite(\"xyz\", \"XYZ\") returns %d\n", strcmp_ite("xyz", "XYZ"));
  printf("strcmp_ite(\"abc\", \"XYZ\") returns %d\n", strcmp_ite("abc", "XYZ"));
  printf("strcmp_ite(\"abc\", \"xYZ\") returns %d\n", strcmp_ite("abc", "xYZ"));
  printf("\n------------------------------------------------------\n");

  printf("The recursive version:\n\n"); 
  printf("strcmp_rec(\"book\", \"desk\") returns %d\n", strcmp_rec("book", "desk"));
  printf("strcmp_rec(\"abc\", \"abc\") returns %d\n", strcmp_rec("abc", "abc"));
  printf("strcmp_rec(\"abc\", \"abcde\") returns %d\n", strcmp_rec("abc", "abcde"));
  printf("strcmp_rec(\"xyz\", \"XYZ\") returns %d\n", strcmp_rec("xyz", "XYZ"));
  printf("strcmp_rec(\"abc\", \"XYZ\") returns %d\n", strcmp_rec("abc", "XYZ"));
  printf("strcmp_rec(\"abc\", \"xYZ\") returns %d\n", strcmp_rec("abc", "xYZ"));
  printf("\n------------------------------------------------------\n");
  
  system("pause");

  return 0; 
}




