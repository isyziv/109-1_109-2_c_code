#include <stdio.h>
#include <stdlib.h>
#include "stack_Array.h"

int ReverseStack(stack *s, stack *t) {
  stack temp;
  char elem;
  
  initialStack(&temp);
  
  while (!isEmpty(s)) {
    elem = pop(s);
    push(t, elem);
    push(&temp, elem);
  }
  
  while (!isEmpty(&temp)) {
    push(s, pop(&temp));
  }
}

int isPalindrome(char *str) {
  stack s, t;
  int i, cont = 1;
  char c1, c2;
  
  initialStack(&s);
  initialStack(&t);
  for (i = strlen(str) - 1; i>=0; i--) push(&s, str[i]);
  ReverseStack(&s, &t);
  
  while (cont && !isEmpty(&s) && !isEmpty(&t))
    if (pop(&s) != pop(&t)) cont = 0;
  
  if (cont && isEmpty(&s) && isEmpty(&t)) return 1;
  else {
    while (!isEmpty(&s)) pop(&s);
    while (!isEmpty(&t)) pop(&t);
    return 0;
  }  
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
