#include <stdio.h>
#include <stdlib.h>

// Computing the length of a string, iterative function.
size_t strlen_ite(const char *str) {
  size_t length;

  for (length = 0; str[length] != '\0'; length++) ;
  return length; 
}

// Computing the length of a string, recursive function.
size_t strlen_rec(const char *str) {
  if (*str=='\0') return 0;
  else return (strlen_rec(str+1) + 1); 
}

// Comparing two strings "lexical graphically" order, iterative function.
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

// Comparing two strings "lexical graphically" order, recirsive function.
int strcmp_rec(const char *str1, const char *str2) {
  if (*str1==*str2 && *str1!='\0') return strcmp_rec(str1+1, str2+1);
  else if (*str1<*str2) return -1;
  else if (*str1>*str2) return 1;
  else return 0;
}

char *strcpy(char *str1, const char *str2) {
  int i;
  
  for (i=0; str2[i]!='\0'; i++) str1[i] = str2[i];
  str1[i] = '\0';
  return str1;
}

char *strcat(char *str1, const char *str2) {
  int length=strlen(str1), i;
  
  for (i=0; str2[i]!='\0'; i++) str1[length+i] = str2[i];
  str1[length+i] = '\0';
  return str1;
}

char *strpbrk(const char *str1, const char *str2) {
  int i, j;
  int found = 0;
  
  for (i=0; !found && str1[i]!='\0'; i++)
    for (j=0; !found && str2[j]!='\0'; j++) found = (str1[i]==str2[j]);
  if (found) return &str1[i-1];
  else return NULL;
}

size_t strspn(const char *str1, const char *str2) {
  int i, j;
  int done = 0, length = 0;
  
  for (i=0; !done && str1[i]!='\0'; i++) {
    for (j=0; str2[j]!='\0'; j++) {
      if (str1[i]==str2[j]) {length++; break;}
      else if (length>0 && str2[j+1]=='\0') done = 1;
    }
  }
  return length;
}

char *strstr(const char *str1, const char *str2) {
  char *ptr1, *ptr2, *temp;
  int cont;
  
  for (ptr1=str1; *ptr1!='\0'; ptr1++) {
    if (*ptr1==*str2) {
      if (*(str2+1)=='\0') return ptr1;
      temp = ptr1 + 1;
      cont = 1;
      for (ptr2=str2+1; cont && *ptr2!='\0'; ptr2++)
        if (*temp!=*ptr2) cont = 0;
        else if (*(ptr2+1)=='\0') return ptr1;
        else temp++;
    }
  }
  return NULL;      
}

int main(void) {

  char A[]="1234444444567834567890abcde";
  char B[]="4444";
  
  // Testing code for strlen().
  printf("String A: %s, String B: %s\n\n", A, B);
  printf("Iterative version: Length of A: %d, Length of B: %d\n\n", strlen_ite(A), strlen_ite(B));
  printf("Recursive version: Length of A: %d, Length of B: %d\n\n", strlen_rec(A), strlen_rec(B));
  
  // Testing code for strcmp().
  
/*
  //
  printf("The first occurrence of B in A, strstr: %0X\n\n", strstr(A, B));
  printf("Address of A: %0X, Address of B: %0X\n\n", A, B);
*/
  
  system("pause");
  return 0; 
}
