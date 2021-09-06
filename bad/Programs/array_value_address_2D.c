/* This porgram shows the value and address of two-dimensional
   array score.
*/

#include <stdio.h>

int main(void) {
  int data[3][4] = {{12, 16, 23, 18},
                    {31, 25, 30, 35},
                    {15, 11, 20, 26}};
  
  printf("****** Case 1:\n");
  printf("Address of data: 0X%X \n", &data);
  printf("Content of data: 0X%X \n", data);
  printf("Address of data[0]: 0X%X\n", &data[0]);
  printf("Content of *data: 0X%X\n", *data);
  printf("Content of data[0]: 0X%X\n", data[0]);
  printf("Address of data[0][0]: 0X%X\n", &data[0][0]);
  
  printf("\n****** Case 2:\n");
  printf("Value of **data: %d\n", **data);
  printf("Value of *data[0]: %d\n", *data[0]);
  printf("Value of data[0][0]: %d\n", data[0][0]);
  
  printf("\n****** Case 3:\n");
  printf("Content of data+1: 0X%X \n", data+1);
  printf("Address of data[1]: 0X%X\n", &data[1]);
  printf("Content of *(data+1): 0X%X\n", *(data+1));
  printf("Content of data[1]: 0X%X\n", data[1]);
  printf("Address of data[1][0]: 0X%X\n", &data[1][0]);
  
  printf("\n****** Case 4:\n");
  printf("Value of **(data+1): %d\n", **(data+1));
  printf("Value of *data[1]: %d\n", *data[1]);
  printf("Value of data[1][0]: %d\n", data[1][0]);
  
  printf("\n****** Case 5:\n");  
  printf("Content of *(data+1)+2: 0X%X \n", *(data+1)+2);
  printf("Content of data[1]+2: 0X%X\n", data[1]+2);
  printf("Address of data[1][2]: 0X%X\n", &data[1][2]);
  
  
  printf("\n****** Case 6:\n");
  printf("Value of *(*(data+1)+2): %d\n", *(*(data+1)+2));
  printf("Value of *(data[1]+2): %d\n", *(data[1]+2));
  printf("Value of data[1][2]: %d\n", data[1][2]);  
  
  system("pause");
  return 0; 
}
