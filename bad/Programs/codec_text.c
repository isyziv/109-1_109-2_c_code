#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  char str1[80], str2[80];//要輸入之字串
  int i;
  char *buffer;
  FILE *fptr;
  int leng;
    
  //編碼表 
  char code_letter[26] = {'H', 'Z', 'J', 'L', 'K', 'A', 'M', 'X', 'D', 'R', 'V', 'W', 'Y',
                        'O', 'C', 'G', 'N', 'T', 'B', 'Q', 'S', 'I', 'U', 'E', 'P', 'F'};
  char code_digit[10] = {};
     
  if (argc==1) {
    printf("Please enter a text file.\n");
    system("pause");
    return -1;
  }
  if (argc>2) {
    printf("To many files are entered.\n");
    system("pause");
    return -1;
  }

  fptr = fopen(argv[1], "r");
  if (fptr==NULL) {
    printf("\nText file \"%s\" does not exist.\n", argv[1]);
    return -1;
  }
  
  fseek(fptr, 0, SEEK_END);
  leng = tell(fptr);
  fseek(fptr, 0, SEEK_SET);
  buffer = (char *) malloc((leng + 1) * sizeof(char));
  fread(buffer, 1, leng, fptr);
  buffer[leng] = '\0';
  fclose(fptr);
  
  for (i=0;i<leng;i++) {
    if (islower(buffer[i])) buffer[i]=toupper(buffer[i]);
  }
    
  for (i=0;i<leng;i++) {
    if (isalpha(buffer[i])) buffer[i] = code_letter[buffer[i] - 65];
    else if (isdigit(buffer[i])) buffer[i] = code_digit[buffer[i] - 65];
  }
  
  fptr = fopen("result.txt", "w");
  fwrite(buffer, 1, leng, fptr);
  fclose(fptr);
     
  printf("%s", buffer);
  
  system("pause");
  return 0;
}
