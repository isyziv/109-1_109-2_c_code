#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"

int main(void) {
  stack s, t;
  int i;

  initialStack(&s);
  initialStack(&t); 

  for (i = 0; i < 50; i++) push(&s, i);
  printf("\nPrint stack s (from top to bottom):\n");
  printStack(&s);
  printf("\n");

  while (!isEmpty(&s)) push(&t, pop(&s));
  printf("\nPrint stack t (from top to bottom):\n");
  printStack(&t);
  printf("\n\n");
  
  system("pause");
  return 0;
}
