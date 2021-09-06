#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

// Initialize a list to the empty list.
void create_list(list* LPtr) {
  LPtr->min = NULL;
  LPtr->max = NULL;
}

// Search the node of a given key value in a list.
// Return a pointer to the node with the key value, if
// search succeeds; return the NULL pointer, if search
// fails.
nodePtr search_list(list L, int key) {
  nodePtr current=L.min;
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
  nodePtr current=LPtr->min, newnode;
  
  if (current==NULL || current->elem>=key) {
    newnode = (nodePtr) malloc(sizeof(struct Node));
    newnode->elem = key;
    newnode->prev = NULL;
    newnode->next = current;
    if (current!=NULL) current->prev = newnode;
    else LPtr->max = newnode;
    LPtr->min = newnode;
  }  
  else {
    while (current->next!=NULL && current->next->elem<key) {
      current = current->next;
    }
    newnode = (nodePtr) malloc(sizeof(struct Node));
    newnode->elem = key;
    newnode->prev = current;
    newnode->next = current->next;
    if (current->next!=NULL) current->next->prev = newnode;
    else LPtr->max = newnode;
    current->next = newnode;
  }      
}

// Delete node of a given key value from a list, if there exists
// a node with the key value. Returns 1, if the deletion succeeds;
// return 0, if the deletion fails.
int delete_list(list* LPtr, int key) {
  nodePtr current=LPtr->min;
  int cont = 1;
  
  if (current==NULL || current->elem>key) {
    return 0;
  }
  else if (current->elem==key) {
    LPtr->min = current->next;
    if (current->next!=NULL) current->next->prev = NULL;
    else LPtr->max = NULL;
    free(current);
    return 1;
  }
  else {
    while (1) {
      if (current==NULL || current->elem>key) return 0;
      else if (current->elem==key) {
        current->prev->next = current->next;
        if (current->next!=NULL) current->next->prev =  current->prev;
        else LPtr->max = current->prev;
        free(current);
        return 1;
      }
      else {
        current = current->next;
      }
    }
  }      
}

// Print all data values of a list in the increasing order.
void print_list_increasing(list L) {
  nodePtr current = L.min;
  
  while (current!=NULL) {
    printf("%3d ", current->elem);
    current = current->next;
  }
}

// Print all data values of a list in the decreasing order.
void print_list_decreasing(list L) {
  nodePtr current = L.max;
  
  while (current!=NULL) {
    printf("%3d ", current->elem);
    current = current->prev;
  }
}
