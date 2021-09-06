#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char fName1[20], fName2[20], fName3[20], *buffer;
  FILE *fPtr;
  int fLeng1, fLeng2;
  
  printf("Enter the name of the first input file: ");
  scanf("%s", fName1);
  fPtr = fopen(fName1, "r");
  if (fPtr==NULL) {
    printf("\nFile %s does not exist.\n\n", fName1);
    system("pause");
    return -1;
  }    
  fseek(fPtr, 0, SEEK_END);
  fLeng1 = ftell(fPtr);
  fseek(fPtr, 0, SEEK_SET);
  buffer = (char *) malloc((fLeng1 + 4) * sizeof(char));
  fread(buffer, 1, fLeng1, fPtr);  
  fclose(fPtr);
  buffer[fLeng1] = '#';
  buffer[fLeng1+1] = '#';
  buffer[fLeng1+2] = '#';
  buffer[fLeng1+3] = '#';
  
  printf("Enter the name of the second input file: ");
  scanf("%s", fName2);
  fPtr = fopen(fName2, "r");
  if (fPtr==NULL) {
    printf("\nFile %s does not exist.\n\n", fName2);
    system("pause");
    return -1;
  }
  fseek(fPtr, 0, SEEK_END);
  fLeng2 = ftell(fPtr);
  fseek(fPtr, 0, SEEK_SET);
  buffer = (char *) realloc(buffer, (fLeng1 + fLeng2 + 5) * sizeof(char));
  fread(&buffer[fLeng1+4], 1, fLeng2, fPtr);  
  fclose(fPtr);
  buffer[fLeng1+fLeng2+4] = '\0';
  
  printf("The resulting file is:\n\n");
  printf("%s\n\n", buffer);
    
  printf("Enter the name of the output file: ");
  scanf("%s", fName3);
  fPtr = fopen(fName3, "w");
  fwrite(buffer, 1, fLeng1+fLeng2+4, fPtr);
  fclose(fPtr);

  system("pause");
  return 0;
}
