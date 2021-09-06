#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

int main(void) {
  stack s, t;
  int count, i;
  
  createStack(&s);
  createStack(&t);
  
  printf("Enter the number of elements: ");
  scanf("%d", &count);
  for (i = 0; i < count; i++) push(&s, rand() % 100);
  printf("\nPrint stack s (from top to bottom):\n");
  printStack(&s);
  printf("\n");
  
  while (!isEmpty(&s)) push(&t, pop(&s));
  printf("\nPrint stack t (from top to bottom):\n");
  printStack(&t);
  printf("\n");
  
  system("pause"); 
  return 0; 
}
