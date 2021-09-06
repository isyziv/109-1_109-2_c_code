#include <stdio.h>
#include <math.h> // Mathematical function library

int main(void) {
  int again=1, op;
  float num;
  
  while (again) { // An definite loop. The loop will be repeated until again=0.
    printf("\n1. Sine function");
    printf("\n2. Cosine function");
    printf("\n3. Square root function");
    printf("\nPlease enter an operation: ");
    scanf("%d", &op);
    // Input a number if it is an expected operation.
    if (op==1 || op==2 || op==3) { 
      printf("Please enter a number: ");
      scanf("%f", &num);
    }    
    
    // Perform proper operation according to the value of op.
    switch (op) { 
      case 1: {
        printf("\nThe sine function of %5.4f is %5.4f.\n", num, sin(num));
        break; // To exit from the switch statement.
      }
      case 2: {
        printf("\nThe cosine function of %5.4f is %5.4f.\n", num, cos(num));
        break;
      }
      case 3: {
        printf("\nThe square root of %5.4f is %5.4f.\n", num, sqrt(num));
        break;
      }
      default: {
        printf("\nFinish.\n");
        again = 0; // Set again to "0". To stop the loop.
        break;
      }
    }
  }
      
  exit(1);
}
