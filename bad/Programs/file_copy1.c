#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *buffer;
  FILE *dataIn, *dataOut;
  int fLeng;
  
  dataIn = fopen("source.txt", "r");
  if (dataIn==NULL) {
    printf("\nText file \"source.txt\" does not exist.\n\n");
    system("pause");
    return -1;
  }
    
  fseek(dataIn, 0, SEEK_END);
  fLeng = ftell(dataIn);
  fseek(dataIn, 0, SEEK_SET);
  buffer = (char *) malloc((fLeng + 1) * sizeof(char));
  fread(buffer, 1, fLeng, dataIn);  
  fclose(dataIn);
  buffer[fLeng] = '\0';
  
  printf("%s", buffer);
  
  dataOut = fopen("result.txt", "w");
  fwrite(buffer, 1, fLeng, dataOut);
  fclose(dataOut);

  system("pause");
  return 0;
}
