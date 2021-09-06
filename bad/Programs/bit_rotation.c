#include<stdio.h>
#include<stdlib.h>

int main(void) {
	unsigned int x, y;
	int count;
	char dir;
	
	do {
    printf("Input an eight-digit hexadecimal number: 0X");
	  scanf("\n%8X", &x);
 
 	  do {
      printf("Enter character 'R' for right rotation , 'L' for left rotation: ");
	    scanf("\n%c", &dir);
    } while (dir!='R' && dir!='L');
 
    do {
      printf("Enter the number of bits to be rotated (0 to 32): ");
	    scanf("\n%d", &count);
	    printf("\n");
    } while (count<0 || count>32);
	
	  if (dir=='R') {
      y = (x >> count) | (x << (32-count)); // Shift right n bits and shift left 32-n bits. 
      printf("\nThe input data is 0X%08X.  ", x);
      printf("Right rotation %d bits, ", count); 
      printf("the result is 0X%08X.\n\n", y);
      printf("-------------------------------------------------\n\n");
    }
    else if (dir=='L') {
      y = (x << count) | (x >> (32-count)); // Shift left n bits and shift right 32-n bits.
      printf("\nThe input data is 0X%08X.  ", x);
      printf("Left rotation %d bits, ", count); 
      printf("the result is 0X%08X.\n\n", y);
      printf("-------------------------------------------------\n\n");
    }     
	} while (x!=0);

	system("pause"); 
	return 0;
  }
