#define max 100

typedef struct {
  int elem[max];
  int ptr;
} stack;

void initialStack(stack *);

int isEmpty(stack *);

int top(stack *);

void push(stack *, int);

int pop(stack *);

void printStack(stack *);

void printStackBottomToTop(stack *);
