#include <stdio.h>
#include <stdlib.h>
#include "double_list_char.h"

// Initialize a list to the empty list.
void initial_list(DList *lst) {
  lst->first = NULL;
  lst->last  = NULL;
}

// Insert a node of a character to the tail of a list.
void insert(DList *lst, char e) {
  nodePtr temp;
  
  temp = (nodePtr) malloc(sizeof(struct Node));
  temp->elem = e;
  temp->next = NULL;
  if (lst->first == NULL) {
    temp->prev = NULL;
    lst->first = temp;
    lst->last  = temp;
  }
  else {
    lst->last->next = temp;
    temp->prev = lst->last;
    lst->last = temp;
  }
}

// Delete a node from the first node of a list.
int delete_first(DList* lst) {
  nodePtr temp;
  
  if (lst->first != NULL) { // The double-linked list is not empty.
    if (lst->first == lst->last) {  // Only one node in the list.
      free(lst->first);
      lst->first = NULL;
      lst->last  = NULL;
      return 1; // Deletion succeeds.
    }
    else {
      temp = lst->first;
      lst->first = temp->next;
      lst->first->prev = NULL;
      free(temp);
      return 1; // Deletion succeeds.
    }
  }
  else return 0; // The double-linked list is empty. Deletion fails.
}

// Delete a node the last node of a queue.
int delete_last(DList *lst) {
  nodePtr temp;
  
  if (lst->last != NULL) { // The double-linked list is not empty.
    if (lst->first == lst->last) {  // Only one node in the list.
      free(lst->last);
      lst->first = NULL;
      lst->last  = NULL;
      return 1; // Deletion succeeds.
    }
    else {
      temp = lst->last;
      lst->last = temp->prev;
      lst->last->next = NULL;
      free(temp);
      return 1; // Deletion succeeds.
    }
  } 
  else return 0; // The double-linked list is empty. Deletion fails.
}

// Print all elements of a list from the head to the tail.
void print_list(DList lst) {
  nodePtr temp = lst.first;
  
  while (temp != NULL) {
    printf("%c", temp->elem);
    temp = temp->next;
  }
  printf("\n\n");
}

// Print all elements of a list from the tail to the head.
void print_list_reverse(DList lst) {
  nodePtr temp = lst.last;
  
  while (temp != NULL) {
    printf("%c", temp->elem);
    temp = temp->prev;
  }
  printf("\n\n");
}
