#include <stdio.h>
#include <stdlib.h>
int foo()
{
  return 1000;
}

int main(void)
{
  int x = 1;
  double y = 1;

  printf("%d\n", foo(x, y));

  system("pause");
  return 0;
}
