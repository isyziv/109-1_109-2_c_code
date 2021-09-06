#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

// data: a byte array of the input data, left-aligned, the "first" bit is at the MSB of data[0].
// bit_length: the number of bits of the input data.
// The return value is an 8-bit data only the first five bits starting from MSB are CRC5.
unsigned char calculate_CRC5(unsigned char * data, unsigned short bit_length) {
  const unsigned char poly5 = 0X48; // polynominal coeficients, higher degree is on the left-hand-side.
  unsigned char CRC5 = 0X48; // preset CRC5
  bool XOR; // XOR of Q4 and the current data bit
  unsigned short byte_count = bit_length / 8; // number of full byte of the input data.
  unsigned short bit_count; // number of bits to be processed in the current byte.
  
  for (unsigned char i=0; i<=byte_count; i++) {
    unsigned char data_in = data[i]; // the current processed byte.
    
    if (i<byte_count) bit_count = 8; // bit_count is 8, if a full byte is processed.
    else bit_count = bit_length % 8; // number of bits in the last byte of the input data.
    
    for (unsigned char j=0; j<bit_count; j++) {
	  XOR = ((CRC5 & 0x80)!=0); // value of Q4.
      if ((data_in & 0x80)!=0) XOR = !XOR; // XOR of Q4 and the current data bit.
      
	  CRC5 = CRC5 << 1; // shift CRC one bit to the left, i.e., Q4<=Q3, Q3<=Q2, ..., Q1<=Q0, Q0<=0.
	  if (XOR) CRC5 = CRC5 ^ poly5; //  performe XOR of the polynominal.
	  data_in = data_in << 1;
	}
  }
  return CRC5; // When checking CRC16, the result should be zero.
}

int main(void) {
  unsigned char s1[100] = {0X30, 0X00, 0X11, 0X11, 0X22, 0X22, 0X33, 0X33, 0X44, 0X44, 0X55, 0X55, 0X66, 0X66, 0X08};  
  printf("Calculating S1: %02X\n", calculate_CRC5(s1, 112)); // calculate CRC5  
  printf("Checking S1:    %02X\n\n", calculate_CRC5(s1, 128)); // check CRC5
  
  unsigned char s2[100] = {0X4C, 0X62, 0X0A, 0XF4, 0X63, 0XDB, 0XC0};  
  printf("Calculating S2: %02X\n", calculate_CRC5(s2, 45)); // calculate CRC5  
  printf("Checking S2:    %02X\n\n", calculate_CRC5(s2, 61)); // check CRC5
  
  system("pause");
}
