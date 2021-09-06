#include <stdio.h>
#include <stdlib.h>
#include "circular_double_list_char.h"

// Initialize a list to the empty list.
void initial_list(List *first) {
  // Complete this function.
}

// Insert a node of a character to the tail of a list.
void insert(List *first, char e) {
  nodePtr temp, last;
  
  temp = (nodePtr) malloc(sizeof(struct Node));
  temp->elem = e;
  if (*first == NULL) { // When the list is empty. 
    // Complete this program segment.
  }
  else { // When the list is not empty.
    // Complete this program segment.
  }
}

// Delete a node from the head of a list.
int delete_first(List* first) {
  nodePtr temp;
  
  if (*first!=NULL) { // Check whether the list is empty.
    temp = (*first)->prev;
    if (temp==*first) { // Only one node in the list.
    // Complete this program segment.
    }
    else if (temp==(*first)->next) { // Two nodes left in the list.
    // Complete this program segment.
    }
    else { // More than two nodes left in the list.
    // Complete this program segment.
    return 1; // Deletion succeeds.
    }
  }
  else return 0; // Deletion fails.
}

// Delete a node from the tail of a queue.
int delete_last(List *first) {
  nodePtr temp;
  
  if (*first!=NULL) { // Check whether the list is empty.
    temp = (*first)->prev;
    if (temp==*first) { // Only one node in the list.
    // Complete this program segment.
    }
    else if (temp==(*first)->next) { // Two nodes left in the list.
    // Complete this program segment.
    }
    else { // More than two nodes left in the list.
    // Complete this program segment.
    }
  }
  else return 0; // Deletion fails.
}

// Print all elements of a list from the head to the tail.
void print_list(List first) {
  nodePtr temp;
  
  if (first!=NULL) {
  // Complete this program segment.
  }
  printf("\n\n");
}

// Print all elements of a list from the tail to the head.
void print_list_reverse(List first) {
  nodePtr temp;
  
  if (first!=NULL) {
  // Complete this program segment.
  }
  printf("\n\n");
}
