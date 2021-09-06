#include<stdio.h>
#include<stdlib.h>

int main(void) {
	unsigned int x, y;
	int i;
	
	do {
    printf("Input a non-negative integer (in decimal format): ");
	  scanf("\n%d", &x);
	  
	  printf("The hexadecimal representation is: 0X%08X\n", x);
	  printf("The binary representation is: ");
	  for (i=1; i<=32; i++) { // Extract the i-th bit of x from the right-hand-side.
	    printf("%d", (x>>32-i)&1);
	    if ((i%4)==0) printf(" ");
	  }
   printf("\n\n--------------------------------------------------\n\n");
	} while (x!=0);

	system("pause"); 
	return 0;
  }
