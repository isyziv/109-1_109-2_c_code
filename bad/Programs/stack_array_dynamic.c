#include <stdio.h>
#include <stdlib.h>
#include "stack_array_dynamic.h"

void createStack(stack *s) {
  s->elem = (int *) malloc(sizeof(int) * 10);
  s->ptr = -1;
  s->size = 10;
}

int isEmpty(stack *s) {
  return (s->ptr < 0);
}

void push(stack *s, int e) {
  if (s->ptr+1 == s->size) {
    s->size += 10;
    s->elem = (int *) realloc(s->elem, sizeof(int) * s->size);
  }
  s->elem[++s->ptr] = e;
}

int pop(stack *s) {
  int e;
  if (s->ptr > -1) e = s->elem[s->ptr--];
  else {
    printf("Stack underflow.\n");
    return int_min;
  }
  if (s->ptr < s->size-15) {
    s->size -= 10;
    s->elem = (int*) realloc(s->elem, sizeof(int) * s->size);
  }
  return e;
}

int top(stack *s) {
  if (s->ptr >= 0) return s->elem[s->ptr];
  else {
    printf("Stack empty.\n");
    return int_min;
  }
}

void printStack(stack *s) {
  int i;

  for (i = s->ptr; i>-1; i--)
    printf("%3d ", s->elem[i]);
}
