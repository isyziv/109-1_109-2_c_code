#include <stdio.h>
#include <stdlib.h>

struct Node {
  char *token;
  struct Node *next;
};
typedef struct Node *nodePtr;
typedef nodePtr list;

int main(void)
{
  char fName[20], *buffer, *str;
  FILE *fPtr;
  int fLeng, tLeng, i;
  nodePtr nPtr, current;
  list L = NULL;
  
  printf("Enter the input text file: ");
  scanf("%s", fName);
  fPtr = fopen(fName, "r");
  if (fPtr==NULL) {
    printf("\nText file %s does not exist.\n\n", fName);
    system("pause");
    return -1;
  }
    
  fseek(fPtr, 0, SEEK_END);
  fLeng = ftell(fPtr);
  fseek(fPtr, 0, SEEK_SET);
  buffer = (char *) malloc((fLeng + 1) * sizeof(char));
  i = 0;
  while (!feof(fPtr)) buffer[i++] = fgetc(fPtr);
  fread(buffer, 1, fLeng, fPtr);  
  fclose(fPtr);
  buffer[i] = '\0';
  
  str = buffer;
  while (1) {
    str = strpbrk(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    if (str==NULL) break;
    nPtr = (nodePtr) malloc(sizeof (struct Node));
    nPtr->token = str;
    nPtr->next = NULL;
    tLeng = strspn(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    if (str[tLeng]!='\0') {
      str[tLeng] = '\0';
      str = str + tLeng + 1;
    }
    else {
      str = str + tLeng;
    }
    if (L==NULL) L=nPtr;
    else {
      current = L;
      while (current->next!=NULL) current =  current->next;
      current->next = nPtr;
    }
    printf("check 1: %s\n", nPtr->token);
  }
  
  printf("Enter the output text file: ");
  scanf("%s", fName);
  fPtr = fopen(fName, "w");
  current = L;
  while (current!=NULL) {
    printf("%s", current->token);
    fprintf(fPtr, "%s", current->token);
    if (current->next!=NULL) {
      printf("---");
      fprintf(fPtr, "---");
    }
    current = current->next;
  }
  printf("\n\n");
  fclose(fPtr);

  system("pause");
  return 0;
}
