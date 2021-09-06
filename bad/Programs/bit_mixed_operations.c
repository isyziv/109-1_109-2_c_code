#include<stdio.h>
#include<stdlib.h>

int main(void) {
	unsigned int X, Y, Z, U;
	int i;
	
	printf("Input an eight-digit hexadecimal number X: 0X");
	scanf("%8X", &X);
	printf("\n");
	
	Y = 0; // Initialize Y to 0.
	Z = 0X05050505; // Initialize Z to be four pairs of 0X05.
	for (i=0; i<4; i++) {
	  // Extract nibble X_2i (X_0, X_2, X_4, X_6). 
	  U = (X >> (8 * i)) & 15;
	  // Place X_2i and complement of X_2i in the 2i-th and (2i+1)-st nibble of Y (from right to left).
	  // (U ^ 15) the the complement of nibble X_2i.
	  Y = Y | (U << (8 * (4 - i) - 4)) | ((U ^ 15) << (8 * (3 - i)));
	  
	  // Extract nibble X_2i+1 (X_1, X_3, X_5, X_7).
	  U = (X >> (8 * i + 4)) & 15;
	  // Place X_2i+1 in the right position of Z.
	  Z = Z | (U << (8 * (4 - i) - 4));
  }
		
	printf("The vaule of X: 0X%08X\n", X);
	printf("The vaule of Y: 0X%08X\n", Y);
	printf("The vaule of Z: 0X%08X\n\n", Z);
	   
	system("pause"); 
	return 0;
}
