#include <stdio.h>
#include <math.h>

// Print a binary string of num with a specified bit length exp.
void printBinary(int num, int exp) {
  int base, radix;
  
  base = (int) pow(2, exp);
  radix = base / 2;
  num = num % base;
  do {
    printf("%1d%", num / radix);
    num = num % radix;
    radix = radix / 2;
  } while (radix != 0);
}

// Parameters a and b represent the two input bits.
// Parameters s and c represent the sum bit and the carry bit, respectively.
// The initial value of parameter c is the input carry and its final value is the output carry.
// Note that, parameters s and c are declared as call-by-address variables.
// Hence, the assignment statements in "fullAdder" should be "*s = ...; *c = ...;"
// The initial value of parameter c is the input value of the carry bit.
// The final value of parameter c is the output value of the carry bit.
// The final value of parameter s is the output value of the sum bit.
// All values of a, b, c, and s should be either 0 or 1 only.
void fullAdder (int a, int b, int *c, int *s) {

  /******************************************************
    Complete the function body of "fullAdder".
    That is, compute the sum bit s and the carry bit c.
    Use LOGICAL OPERATIONS ONLY.
  ******************************************************/

}

// Parameters x and y are two non-negative operands
// which are represented as two 16-bit binary numbers.
// Function Adder will return the sum of x and y.
// The sum is represented as a 17-bit binary number.
// Variable s represents the sum bit of a fullAdder.
// Variable c represents the carry bit. Initially, the carry bit is set to 0.
// Variable pos represents the poistion of the bit being processed.
// The least significant bit is of position 0 and the most significant bit is of position 15.
// The value of variable sum should be returned at the end of function Adder.
// Variable x0 and y0 represent the current bit of x and y that will be processed by fullAdder.
int Adder(int x, int y) {

  int s, c = 0, pos, sum = 0;
  int x0, y0;
  
  for (pos = 0; pos <16; pos++) {
  
    // **********************************************************************************
    // The loop body calls fullAdder to add two operand bits and a carry bit.
    // The loop body should include the following steps.
    // You are going to use LOGICAL OPERATIONS ONLY to implement these steps:
    
    // Step 1: set x0 to the current bit of x, i.e., the least significant bit of x.
    
    // Step 2: set y0 to the current bit of y, i.e., the least significant bit of y.
    
    // Step 3: call fullAdder to add x0, y0 , and the input carry bit c and
    //         to return the sum bit s and the output carry bit c.
    
    // Step 4: update x to shift its bit string one position to the right-hand-side.
    
    // Step 5: update y to shift its bit string one position to the right-hand-side.
    //         The shift operation is to move the next processed bit of x and y to the
    //         least significant bit.
    
    // Step 6: place the sum bit s in sum to the appropriate position specified by pos.
    // **********************************************************************************
  }
  
  // ***************************************************************************** 
  // Place the final carry bit in sum to the appropriate position specified by pos.
  
  // Return the result sum.
  // ***************************************************************************** 
  
}

int main(void) {

  int a, b, r;
  
  // Input two 16-bit non-negative integers.
  printf("Enter the first non-negative integers between 0 and 65535: ");
  scanf("%d", &a);
  printf("\nEnter the second non-negative integers between 0 and 65535: ");
  scanf("%d", &b);
  printf("\n");
  
  // Print the binary representation of the two input integers.
  printf("a = %5d, Binary value: ", a);
  printBinary(a, 16);
  printf("\n");
  printf("b = %5d, Binary value: ", b);
  printBinary(b, 16);
  printf("\n");
  
  // Call function Adder to add the two integers a and b and store it in variable r.
  r = Adder(a, b);
  printf("r = %5d, Binary value: ", r);
  if ((r >> 16) == 0) printBinary(r, 16); // If the final carry is 0, print a 16-bit binary number.
  else printBinary(r, 17);                // If the final carry is 1, print a 17-bit binary number.
  printf("\n\n");
  
  // Print the testing message.
  if (a + b == r) printf("Correct! Adder operation test: %d + %d = %d\n\n", a, b, r);
  else printf("Incorrect! Adder operation test: %d + %d != %d\n\n", a, b, r);
  
  system("pause");
  return 0;
}
