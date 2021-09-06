#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

stack p1, p2, p3;

void printPoles(void) {
  printf("**********************************************************\n");
  printf("Pole 1: ");
  printStack(&p1);
  printf("\nPole 2: ");
  printStack(&p2);
  printf("\nPole 3: ");
  printStack(&p3);
  printf("\n");
}

void hanoi(int n, stack* pole1, stack* pole2, stack* pole3) {
  if (n > 0) {
    hanoi(n-1, pole1, pole3, pole2);
    push(pole3, pop(pole1));
    printPoles();
    hanoi(n-1, pole2, pole1, pole3);
  }
}

int main(void) {
  int n, i;
  
  printf("Please input number: ");
  scanf("%d",&n); // Enter a number n.
  
  if(n > 24) { // The number n cannot be too large.
    printf("Number n is too large. \n");
    system("pause");
    exit(1);
  }
  
  if(n < 0) { // The number n cannot be a negative number.
    printf("Input error. Number n must be greater than 0.\n");
    system("pause"); 
    exit(1);
  }
  
  createStack(&p1);
  createStack(&p2);
  createStack(&p3);
  for (i = n; i > 0; i--) push(&p1, i);
  printPoles();
  hanoi(n, &p1, &p2, &p3);
  printf("\nFinish!!!\n");
  //system("pause");
}


