/* This program is the header file of complex number arithmetic
   operation. A complex number is represened as a
   pair of floating point numbers.
   Four operations of complex number addition, subtraction,
   multiplication, and division are defined as functions.

   Define a new data type of complex numbers.
   A complex number is represented as a pair of two
   floating point numbers, one for the real part and 
   another for the imaginary part.
*/
typedef struct {
  float re;
  float im;
} complex;

// Complex number addition
complex add(complex, complex);

// Complex number substraction
complex subtract(complex, complex);

// Complex number multiplications
complex multiply(complex, complex);

// Complex number division
complex divide(complex, complex);

// Convert a floating-point number to a complex number
complex r2c(float);

// Check the zerop of a complex number
int zerop(complex);

// Print a complex number
void printc(complex);
