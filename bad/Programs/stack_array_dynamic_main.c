#include <stdio.h>
#include <stdlib.h>
#include "stack_array_dynamic.h"

int main(void) {
  stack s;
  int cmd, elem;

  createStack(&s);

  while (1) {
    printf("1. Push an element to the stack.\n");
    printf("2. Pop an element from the stack.\n");
    printf("3. Check if the stack is empty or not.\n");
    printf("4. Print the top element of the stack.\n");
    printf("5. Print all elements of the stack.\n");
    printf("6. Stop.\n");
    printf("**** Enter a command: ");
    scanf("%d", &cmd);
    
    switch (cmd) {
      case 1: {
        printf("\n###### Enter a stack element: ");
        scanf("%d", &elem);
        printf("\n");
        push(&s, elem);
        break;
      }
      case 2: {
        elem = pop(&s);
        if (elem != int_min) printf("\n###### Element %d has been removed.\n\n", elem);
        break;
      }
      case 3: {
        if (isEmpty(&s)) printf("\n###### The stack is empty.\n\n");
        else printf("\n###### The stack is not empty.\n\n");
        break;
      }
      case 4: {
        elem = top(&s);
        if (elem != int_min) printf("\n###### The top element is %d.\n\n", elem);
        break;
      }
      case 5: {
        printf("\n###### The stack elements are (from top to bottom): \n");
        printStack(&s);
        printf("\n\n");
        break;
      }
      case 6: {
        exit(0);
      }
      default: {
        printf("\n###### Invalid command.\n\n");
      }
    }    
  }
}
