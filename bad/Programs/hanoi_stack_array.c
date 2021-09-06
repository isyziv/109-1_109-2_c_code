#include <stdio.h>
#include <string.h>
#include "hanoi_stack_array.h"

void initialStack(stack *s, char *name) {
  strcpy(s->name, name);
  s->ptr = -1;
}

char *getName(stack *s) {
  return s->name;
}

int isEmpty(stack *s) {
  return (s->ptr < 0);
}

int top(stack *s) {
  if (s->ptr >= 0) return s->elem[s->ptr];
  else {
    printf("Stack empty.\n");
    return -1;
  }
}

void push(stack *s, int e) {
  if (s->ptr < max-1) s->elem[++s->ptr] = e;
  else printf("Stack overflow.\n");
}

int pop(stack *s) {
  if (s->ptr > -1) return s->elem[s->ptr--];
  else printf("Stack underflow.\n");
}

void printStack(stack *s) {
  int i;

  for (i = s->ptr; i>-1; i--)
    printf("%4d", s->elem[i]);
}

void printStackBottomToTop(stack *s) {
  int i;

  for (i = 0; i<=s->ptr; i++)
    printf("%4d", s->elem[i]);
}
