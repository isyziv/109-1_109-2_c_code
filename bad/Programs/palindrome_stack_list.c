#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack_list1.h"

int ReverseStack(stack *s, stack *t) {
  stack temp;
  char elem;
  
  createStack(&temp);
  
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
  
  createStack(&s);
  createStack(&t);
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
  char *str;
  char ch;
  int index, length;
  
  while (1) {
    index = 0;
    length = 21;
    str = NULL;
    str = (char *) realloc(str, sizeof(char) * length);
    if (str==NULL) {
      printf("\n **** Out of system resource!!!\n");
      system("pause");
      return 0;
    }  
    printf("Enter a string: ");
    /* The following do-while assumes that the length of the input string
       is not known and it can be a very long string. Hence, a dynamic array
       is used to store the string. Initially, the size of the array is set
       to hold 20 characters (length 21, including the end of string NULL
       character.) The array is expanded ten more characters once it is filled
       up.
       If the input string is limited to a maximum length. The program can
       declare a fix-sized array and use scanf() to replace the following
       do-while loop.
    */
    do {
      ch = getchar();
      if (!isspace(ch)) {
        str[index] = ch;
        if (index+2==length) {
          str = (char *) realloc(str, length+=10);
          if (str==NULL) {
            printf("\n **** Out of system resource!!!\n");
            system("pause");
            return 0;
          }  
        }  
      }
      else str[index] = '\0';
    } while (str[index++]!='\0');
    
    if (strcmp(str, "000")) {
      if (isPalindrome(str)) printf("\n**** %s is a palindrome.\n\n", str);
      else  printf("\n**** %s is not a palindrome.\n\n", str);
      free(str);
      printf("------------------------------------------------\n\n");
    }  
    else return 0;     
  }
}
