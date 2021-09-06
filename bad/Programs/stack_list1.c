#include <stdio.h>
#include <stdlib.h>
#include "stack_list1.h"

void createStack(stack *s) {
  *s = NULL;
}

int isEmpty(stack *s) {
  return (*s == NULL);
}

void push(stack *s, char e) {
  nodePtr temp;

  temp = (nodePtr) malloc(sizeof (struct Node));
  temp->elem = e;
  temp->next = *s;
  *s = temp;
}

char pop(stack *s) {
  nodePtr temp;
  char e;
  
  if (*s != NULL) {
    temp = *s;
    e = temp->elem;
    *s = temp->next;
    free(temp);
    return e;
  }
  else {
    printf("Stack underflow.\n");
    return '\0';
  }
}

char top (stack *s) {
  if (*s != NULL) return (*s)->elem;
  else {
    printf("Stack empty.\n");
    return '\0';
  }
}

void printStack(stack *s) {
  nodePtr temp = *s;
  while (temp != NULL) {
    printf("%c ", temp->elem);
    temp = temp->next;
  }
}

