/* This program illustrates the use of switch-case statement.
   Since no break statement is placed at the end of each case,
   the statements starting from the selected case are executed.
*/
#include <stdio.h>

int main(void) {
  int x;
  
  printf("Enter an integer: ");
  scanf("%d", &x);
   
  switch (x) {
    case 1: printf("one\n");
    case 2: printf("two\n");
    case 3: printf("three\n");
    case 4: printf("four\n");
    default: printf("others\n");
  }

  system("pause");
  return 0; 
}



