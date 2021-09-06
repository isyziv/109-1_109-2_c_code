#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char * s) {

  int h = 0, t = strlen(s) - 1;
  
  while (h<t) if (s[h++]!=s[t--]) return 0;
  return 1;
}

int main(void) {
  char str[101];
  
  while (1) {
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (strcmp(str, "000")) {
      if (isPalindrome(str)) printf("\n**** %s is a palindrome.\n\n", str);
      else  printf("\n**** %s is not a palindrome.\n\n", str);
      printf("------------------------------------------------\n\n");
    }  
    else {
      printf("\n");
      system("pause");
      return 0;
    }
  }
}
