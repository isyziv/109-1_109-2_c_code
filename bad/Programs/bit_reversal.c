#include<stdio.h>
#include<stdlib.h>

int main(void) {
	unsigned int x, y, z;
	int i;
	
	printf("Input an eight-digit hexadecimal number: 0X");
	scanf("%8X", &x);
	printf("\n");
	
	y = 0;
	z = x;
	for (i=0; i<32; i++) {
	  y = y | (z & 1);        // Insert the left most bit of z to y.
	  z = z >> 1;             // Shift z one bit to the left. 
	  if (i<31) y = y << 1;   // If not finish, shift y one bit to the right.
  }
		
	printf("The value of x: 0X%08X\n", x);
	printf("The bit reversal value of x: 0X%08X\n\n", y);

	system("pause"); 
	return 0;
  }
