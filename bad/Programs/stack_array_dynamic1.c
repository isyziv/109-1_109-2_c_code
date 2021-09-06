#include <stdio.h>
#include "stack_array_dynamic1.h"

void createStack(stack *s) {
  s->elem = (char *) malloc(sizeof(int) * 10);
  s->ptr = -1;
  s->size = 10;
}

int isEmpty(stack *s) {
  return (s->ptr < 0);
}

void push(stack *s, char e) {
  if (s->ptr+1 == s->size) {
    s->size += 10;
    s->elem = (char *) realloc(s->elem, sizeof(int) * s->size);
  }
  s->elem[++s->ptr] = e;
}

char pop(stack *s) {
  if (s->ptr > -1) return s->elem[s->ptr--];
  else {
    printf("Stack underflow.\n");
    return '\0';
  }
  if (s->ptr < s->size-15) {
    s->size -= 10;
    s->elem = (char *) realloc(s->elem, sizeof(int) * s->size);
  }
}

char top(stack *s) {
  if (s->ptr >= 0) return s->elem[s->ptr];
  else {
    printf("Stack empty.\n");
    return '\0';
  }
}

void printStack(stack *s) {
  int i;

  for (i = s->ptr; i>-1; i--)
    printf("%c ", s->elem[i]);
}
