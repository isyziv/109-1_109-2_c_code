#include <stdio.h>
#include <stdlib.h>
#include "circular_double_list_char.h"

// Initialize a list to the empty list.
void initial_list(CDList *first) {
  *first = NULL;
}

// Insert a node of a character to the tail of a list.
void insert(CDList *first, char e) {
  nodePtr temp, last;
  
  temp = (nodePtr) malloc(sizeof(struct Node));
  temp->elem = e;
  if (*first == NULL) { // When the list is empty. 
    *first = temp;
    (*first)->next = *first;
    (*first)->prev = *first;
  }
  else { // When the list is not empty.
    last = (*first)->prev;
    last->next = temp;
    temp->prev = last;
    temp->next = *first;
    (*first)->prev = temp;
  }
}

// Delete a node from the head of a list.
int delete_first(CDList* first) {
  nodePtr temp;
  
  if (*first!=NULL) { // Check whether the list is empty.
    temp = (*first)->prev;
    if (temp==*first) { // Only one node in the list.
      free(*first);
      *first = NULL;
      return 1; // Deletion succeeds.
    }
    else if (temp==(*first)->next) { // Two nodes left in the list.
      temp->next = temp;
      temp->prev = temp;
      free(*first);
      *first = temp;;
      return 1; // Deletion succeeds.
    }
    else { // More than two nodes left in the list.
      ((*first)->next)->prev = temp;
      temp->next = (*first)->next;
      temp = *first;
      *first = temp->next;
      free(temp);
    return 1; // Deletion succeeds.
    }
  }
  else return 0; // Deletion fails.
}

// Delete a node from the tail of a queue.
int delete_last(CDList *first) {
  nodePtr temp;
  
  if (*first!=NULL) { // Check whether the list is empty.
    temp = (*first)->prev;
    if (temp==*first) { // Only one node in the list.
      free(*first);
      *first = NULL;
      return 1; // Deletion succeeds.
    }
    else if (temp==(*first)->next) { // Two nodes left in the list.
      (*first)->next = (*first);
      (*first)->prev = (*first);
      free(temp);
      return 1; // Deletion succeeds.
    }
    else { // More than two nodes left in the list.
      (*first)->prev = temp->prev;
      (temp->prev)->next = *first;
      free(temp);
      return 1; // Deletion succeeds.
    }
  }
  else return 0; // Deletion fails.
}

// Print all elements of a list from the head to the tail.
void print_list(CDList first) {
  nodePtr temp;
  
  if (first!=NULL) {
    temp = first;
    do {
      printf("%c", temp->elem);
      temp = temp->next;
    } while (temp!=first);
  }
  printf("\n\n");
}

// Print all elements of a list from the tail to the head.
void print_list_reverse(CDList first) {
  nodePtr temp;
  
  if (first!=NULL) {
    temp = first->prev;
    do {
      printf("%c", temp->elem);
      temp = temp->prev;
    } while (temp!=first->prev);
  }
  printf("\n\n");
}
