#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void)
{
  char search_string[]="Woody Norm Cliff";
  char *array[50];
  int loop;
  
  
  printf("**** 0X%0X: %s\n\n", search_string, search_string);

  array[0]=strtok(search_string," ");
  printf("**** 0X%0X: %s\n", array[0], array[0]);
  if(array[0]==NULL)
   {
    printf("No test to search.\n");
    exit(0);
   }

  for(loop=1;loop<50;loop++)
   {
    array[loop]=strtok(NULL," ");
    printf("**** 0X%0X: %s\n", array[loop], array[loop]);
    if(array[loop]==NULL)
      break;
   }

  printf("\n"); 
  for(loop=0;loop<50;loop++)
   {
    if(array[loop]==NULL)
      break;
    printf("Item #%d is %s.\n", loop, array[loop]);
   }

  system("pause");
  return 0;
}
