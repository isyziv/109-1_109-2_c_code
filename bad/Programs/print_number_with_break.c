/* This program illustrates the use of switch-case statement.
   Since a break statement is placed at the end of each case
   clause, only the statement in the case clause is executed.
*/
#include <stdio.h>

int main(void) {
  int x;

  printf("Enter an integer: ");
  scanf("%d", &x);

  switch (x) {
    case 1: {
      printf("one\n");
      break;
    }
    case 2: {
      printf("two\n");
      break;
    }
    case 3: {
      printf("three\n");
      break;
    }
    case 4: {
      printf("four\n");
      break;
    }
    default: printf("others\n");
  }
  system("pause");
  return 0; 
}




