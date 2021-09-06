struct Node
{
  int elem;
  struct Node *next;
};

typedef struct Node *nodePtr;
typedef nodePtr stack;

void createStack(stack *);
int isEmpty(stack *);
void push(stack *, int);
int pop(stack *);

int top(stack *);
void printStack(stack *);
