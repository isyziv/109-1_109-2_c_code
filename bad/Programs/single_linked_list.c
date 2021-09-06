#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"

// Initialize a list to the empty list.
void create_list(list* LPtr) {
  *LPtr = NULL;
}

// Search the node of a given key value in a list.
// Return a pointer to the node with the key value, if
// search succeeds; return the NULL pointer, if search
// fails.
nodePtr search_list(list L, int key) {
  nodePtr current=L;
  int found=0;
  
  while (!found && current!=NULL) {
    if (current->elem==key) found = 1;
    else if (current->elem>key) current = NULL;
    else current = current->next;
  }  
  return current;
}

// Insert the node of a given key value in a list.
void insert_list(list* LPtr, int key) {
  nodePtr current=*LPtr, newnode;
  
  if (current==NULL || current->elem>=key) {
    newnode = (nodePtr) malloc(sizeof(struct Node));
    newnode->elem = key;
    newnode->next = current;
    *LPtr = newnode;
  }  
  else {
    while (current->next!=NULL && current->next->elem<key) {
      current = current->next;
    }
    newnode = (nodePtr) malloc(sizeof(struct Node));
    newnode->elem = key;
    newnode->next = current->next;
    current->next = newnode;
  }      
}

// Delete node of a given key value from a list, if there exists
// a node with the key value. Returns 1, if the deletion succeeds;
// return 0, if the deletion fails.
int delete_list(list* LPtr, int key) {
  nodePtr current=*LPtr, previous;
  int cont = 1;
  
  if (current==NULL || current->elem>key) {
    return 0;
  }
  else if (current->elem==key) {
    *LPtr = current->next;
    free(current);
    return 1;
  }
  else {
    previous = current;
    current = current->next;
    while (1) {
      if (current==NULL || current->elem>key) return 0;
      else if (current->elem==key) {
        previous->next = current->next;
        free(current);
        return 1;
      }
      else {
        previous = current;
        current = current->next;
      }
    }
  }      
}

// Print all data values of a list.
void print_list(list L) {
  nodePtr current = L;
  
  while (current!=NULL) {
    printf("%4d ", current->elem);
    current = current->next;
  }
}

