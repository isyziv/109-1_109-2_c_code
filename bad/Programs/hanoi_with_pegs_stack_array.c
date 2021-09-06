/* Tower of Hanoi: Moving n discs from sour via aux to dest.
   This program uses stacks to represent the the pegs.
   After every move, the contents of the pegs are printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include "hanoi_stack_array.h"

// Print the conents of the three pegs.
void printPegs(stack *ppeg1, stack *ppeg2, stack *ppeg3) {
  printf("\nPeg A: ");
  printStackBottomToTop(ppeg1);
  printf("\nPeg B: ");
  printStackBottomToTop(ppeg2);
  printf("\nPeg C: ");
  printStackBottomToTop(ppeg3);

}

/* The first three peg parameters sour, aux, and dest are
   the source peg, auxiliary peg, and destination peg for
   disk movements.
   The next three peg parameters ppeg1, ppeg2, ppeg3 are the
   three pegs in their order for the output purpose.
*/
void hanoi(int n, stack *sour, stack *aux, stack *dest,
           stack *ppeg1, stack *ppeg2, stack *ppeg3) {
  static int step = 1;
  
  if (n>0) {
    hanoi(n-1, sour, dest, aux, ppeg1, ppeg2, ppeg3);
    push(dest, pop(sour));
    printf("\n\n**********************************************\n");
    printf(">>>> Step %d: Move disk %d from %s to %s\n", step++, top(dest), getName(sour), getName(dest));
    printPegs(ppeg1, ppeg2, ppeg3);
    hanoi(n-1, aux, sour, dest, ppeg1, ppeg2, ppeg3);
  }
}

int main(void) {
  stack peg1, peg2, peg3;
  int i, k;

  initialStack(&peg1, "Peg A");
  initialStack(&peg2, "Peg B");
  initialStack(&peg3, "Peg C");

  do {
    printf("Please enter the number of disks: ");
    scanf("%d", &k); // Enter a number n.
  } while (k<1 || k>12);


  for (i=k; i>0; i--) push(&peg1, i);

  printf("\nInitial pegs:\n");
  printPegs(&peg1, &peg2, &peg3); 
  hanoi(k, &peg1, &peg2, &peg3, &peg1, &peg2, &peg3);
  printf("\n\nFinish!!!\n\n");
  
  system("pause");
  return 0;
}
