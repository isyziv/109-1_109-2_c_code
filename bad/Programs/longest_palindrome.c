#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
  char elem;
  struct Node* prev;
  struct Node* next;
} node;

typedef node* nodePtr;

int main(void) {
  char *data;
  nodePtr head=NULL, tail=NULL, temp;
  FILE *fPtr;
  unsigned long leng, count, done, i;
  
  fPtr = fopen("longest_palindrome_in.txt", "r");
  fseek(fPtr, 0, SEEK_END);
  leng = ftell(fPtr);
  fseek(fPtr, 0, SEEK_SET);
  data = (char *) malloc((leng + 1) * sizeof(char));
  fread(data, 1, leng, fPtr);  
  fclose(fPtr);
  data[leng] = '\0';
  
  count = 0;
  for (i=0; i<leng; i++)
    if (isalpha(data[i])) data[count++] = toupper(data[i]);
  data[count] = '\0';
  
  fPtr = fopen("longest_palindrome_out.txt", "w");
  fwrite(data, 1, count, fPtr);
  fclose(fPtr);
  
  for (i=0; i<count; i++) {
    temp = (nodePtr) malloc(sizeof(node));
    temp->elem = data[i];
    if (tail==NULL) {
      temp->next = NULL;
      temp->prev = NULL;
      tail = temp;
      head = temp;
    }
    else {
      temp->next = tail;
      temp->prev = NULL;
      tail->prev = temp;
      tail = temp;      
    }    
  }
  
  done = 0;
  while (!done) {
    if (tail->elem==head->elem) {
      if (tail==head) {
        free(tail);
        done = 1;
      }
      else if (tail->next==head) {  
        free(tail->next);
        free(tail);
        done = 1;
      }
      else {
        temp = tail->next;
        free(tail);
        tail = temp;
        temp = head->prev;
        free(head);
        head = temp;
      }  
    }
    else {
      while (tail!=NULL) {
        temp = tail->next;
        free(tail);
        tail = temp;
      }  
      done = -1;
    }
  }
  
  if (done==1) {
    printf("The longest palindrome has %d characters.\n", count);
    printf("Yes, it is a palindrome.\n");
  }
  else printf("\n\nNo, it is not a palindrome.\n");
    
  system("pause");
  return 0;
}  
