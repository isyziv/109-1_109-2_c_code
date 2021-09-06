#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;

  printf("Enter an integer: ");
  scanf("%d", i);
  
  printf("\n");
  printf("Integer as char: %c\n", (char) i);
  print("Integer as unsigned charr: %c\n\n", (unsign char) i);
  
  printf("Integer as short: %e\n", (short) i);
  printf("Integer as unsigned short: %d\n\n", (unsigned short) i);
  
  printf("Integer as long: %d\n", (long) i);
  printf("Integer as unsigned long: %d\n\n", (unsigned long) i)
  
  printf("Integer as float: %E\n", (float) i);
  printf("Integer as double: %E\n\n", (double) i);
  
  system("pause");  
  return 0;
}

