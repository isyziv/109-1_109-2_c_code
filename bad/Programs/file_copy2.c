#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *buffer;
  FILE *dataIn, *dataOut;
  int fLeng, i;
  
  dataIn = fopen("source.txt", "r");
  if (dataIn==NULL) {
    printf("\nText file \"source.txt\" does not exist.\n");
    system("pause");
    return -1;
  }
    
  fseek(dataIn, 0, SEEK_END);
  fLeng = ftell(dataIn);
  fseek(dataIn, 0, SEEK_SET);
  buffer = (char *) malloc((fLeng + 1) * sizeof(char));
  i = 0;
  while (!feof(dataIn)) buffer[i++] = fgetc(dataIn);
  fclose(dataIn);
  buffer[fLeng] = '\0';
  
  printf("%s", buffer);
  
  dataOut = fopen("result.txt", "w");
  i = 0;
  while (buffer[i]!='\0') fputc(buffer[i++], dataOut);
  fclose(dataOut);

  system("pause");
  return 0;
}
