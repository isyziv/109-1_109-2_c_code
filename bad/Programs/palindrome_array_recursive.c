#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char * s, int h, int t) {
  
  if (s[h]!=s[t]) return 0;
  else if (h>=t) return 1;
  else return isPalindrome(s, ++h, --t);
}

int main(void) {
  char str[101];
  int head, tail;
  
  while (1) {
    printf("Enter a string: ");
    scanf("%s", str);
    
    head = 0, tail = strlen(str) - 1;
    
    if (strcmp(str, "000")) {
      if (isPalindrome(str, head, tail)) printf("\n**** %s is a palindrome.\n\n", str);
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
