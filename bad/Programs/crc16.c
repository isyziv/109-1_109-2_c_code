#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// data: a byte array of the input data, left-aligned, the "first" bit is at the MSB of data[0].
// bit_length: the number of bits of the input data.
// checking: 0 means calculating CRC16 of the input data; 
//           1 means checking CRC16 of the input data (the input data inlcuding CRC16).
// The return value is a 16-bit CRC16.
unsigned short calculate_CRC16(unsigned char * data, unsigned short bit_length, char checking) {
  const unsigned short poly16 = 0X1021; // polynominal coeficients, higher degree is on the left-hand-side.
  unsigned short CRC16 = 0XFFFF; // preset CRC16
  char XOR; // XOR of Q15 and the current data bit
  unsigned short byte_count = bit_length / 8; // number of full byte of the input data.
  unsigned short bit_count; // number of bits to be processed in the current byte.
  unsigned char i, j;
  
  for (i=0; i<=byte_count; i++) {
    unsigned char data_in = data[i]; // the current processed byte.
    
    if (i<byte_count) bit_count = 8; // bit_count is 8, if a full byte is processed.
    else bit_count = bit_length % 8; // number of bits in the last byte of the input data.
    
    for (j=0; j<bit_count; j++) {
	  XOR = ((CRC16 & 0x8000)!=0); // value of Q15.
      if ((data_in & 0x80)!=0) XOR = !XOR; // XOR of Q15 and the current data bit.
      
	  CRC16 = CRC16 << 1; // shift CRC one bit to the left, i.e., Q15<=Q14, Q14<=Q13, ..., Q1<=Q0, Q0<=0.
	  if (XOR) CRC16 = CRC16 ^ poly16; //  performe XOR of the polynominal.
	  data_in = data_in << 1;
	}
  }
  //return CRC16;
  if (checking) return CRC16 ^ 0X1D0F; // When checking CRC16, the result sohuld be 0X1D0F. Passed: return 0; Failed: otherwise.
  else return CRC16 ^ 0XFFFF; // When calculating CRC16, the result is inverted.
}

int main(void) {
  unsigned char s1[100] = {0X30, 0X00, 0X11, 0X11, 0X22, 0X22, 0X33, 0X33, 0X44, 0X44, 0X55, 0X55, 0X66, 0X66, 0X18, 0X35};  
  unsigned char s2[100] = {0X4C, 0X62, 0X0A, 0XF4, 0X63, 0XDE, 0X9E, 0X50};  
  
  printf("Calculating S1: %04X\n", calculate_CRC16(s1, 112, 0)); // calculate CRC16  
  printf("Checking S1:    %04X\n\n", calculate_CRC16(s1, 128, 1)); // check CRC16
  
  printf("Calculating S2: %04X\n", calculate_CRC16(s2, 45, 0)); // calculate CRC16  
  printf("Checking S2:    %04X\n\n", calculate_CRC16(s2, 61, 1)); // check CRC16
  
  system("pause");
  return 0;
}
