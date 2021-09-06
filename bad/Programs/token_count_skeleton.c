#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  unsigned char* str;
  int count;
  struct Node* next;
} node;

typedef node* nodePtr;
typedef nodePtr list;

// Initialize a list to the empty list.
void create_list(list* LPtr) {
  *LPtr = NULL;
}

// Search the node of a given key value in a list.
// Return a pointer to the node with the key value, if
// search succeeds; return the NULL pointer, if search
// fails.
nodePtr search_list(list L, unsigned char* key) {
  nodePtr current=L;
  int found=0;
  
  while (!found && current!=NULL) {
    if (strcmp(current->str, key)==0) {
      current->count++;
      found = 1;
    }  
    else if (strcmp(current->str, key)>0) current = NULL;
    else current = current->next;
  }  
  return current;
}

// Insert the node of a given key value in a list.
void insert_list(list* LPtr, unsigned char* key) {
  nodePtr current=*LPtr, last, newnode;
  
  if (current==NULL || strcmp(current->str, key)>0) {
    newnode = (nodePtr) malloc(sizeof(node));
    newnode->str = key;
    newnode->count = 1;
    newnode->next = current;
    *LPtr = newnode;
  }  
  else {
    last = current;
    current = current->next;
    while (current!=NULL && strcmp(current->str, key)<0) {
      last = current;
      current = current->next;
    }
    newnode = (nodePtr) malloc(sizeof(node));
    newnode->str = key;
    newnode->count = 1;
    last->next = newnode;
    newnode->next = current;
  }      
}

// Print all data values of a list.
void print_list(list L) {
  nodePtr current = L;
  
  while (current!=NULL) {
    printf("%s: %d\n", current->str, current->count);
    current = current->next;
  }
}

int main(int argc, char *argv[]) {
  unsigned char *buffer, *token;  
  char punctuation[]=" ,.;:()\'\?\"\x09\x0A\x0D\x2F";
  FILE *fptr;
  int fLeng, cnt;
  list tokenList;
  
  fptr = fopen("text.txt", "r");
    
  fseek(fptr, 0, SEEK_END);
  fLeng = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  buffer = (unsigned char *) malloc((fLeng + 1) * sizeof(char));
  fread(buffer, 1, fLeng, fptr);  
  fclose(fptr);
  buffer[fLeng] = '\0';
  
  // Complete the rest of the program.
}
