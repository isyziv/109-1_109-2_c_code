/* This program will print the number of bytes of each primitive
   data type. Function sizeof( ) receives a type name as its
   parameter and returns an integer value.
*/

#include <stdio.h>

int main(void) {
  
  printf("Memory size of C primitive data types (bytes): \n");
  printf("  char: %d\n", sizeof(char));
  printf("  int: %d\n", sizeof(int));
  printf("  short: %d\n", sizeof(short));
  printf("  long: %d\n", sizeof(long));
  printf("  long long: %d\n", sizeof(long long));
  printf("  unsigned: %d\n", sizeof(unsigned));
  printf("  unsigned short: %d\n", sizeof(unsigned short));
  printf("  unsigned long: %d\n", sizeof(unsigned long));
  printf("  unsigned long long: %d\n", sizeof(unsigned long long));
  printf("  float: %d\n", sizeof(float));
  printf("  double: %d\n", sizeof(double));
  
  return 0; 
}
