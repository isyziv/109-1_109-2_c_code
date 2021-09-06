#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

// Initialize a list to the empty list.
void initial_queue(Queue* que) {
  que->tail = NULL;
  que->head = NULL;
}

// Enqueue: insert a node of value e to the tail of a queue.
void enqueue(Queue* que, int e) {
  nodePtr temp;
  
  temp = (nodePtr) malloc(sizeof(struct Node));
  temp->elem = e;
  temp->prev = NULL;
  if (que->tail == NULL) {
    temp->next = NULL;
    que->tail = temp;
    que->head = temp;
  }
  else {
    temp ->next = que->tail;
    que->tail->prev = temp;
    que->tail = temp;
  }
}

// Dequeue: delete a node of value e from the head of a queue.
int dequeue(Queue* que) {
  nodePtr temp;
  int e;
  
  if (que->head!=NULL) {
    temp = que->head;
    e = temp->elem;
    if (temp->prev==NULL) {
      que->tail = NULL;
      que->head = NULL;
    }
    else {
      que->head = temp->prev;
      que->head->next = NULL;
    }    
    free(temp);
    return e;
  }
  else return -9999;
}

// Print all elements of a queue from the head to the tail.
void print_queue(Queue que) {
  nodePtr temp = que.head;
  
  while (temp!=NULL) {
    printf("%3d ", temp->elem);
    temp = temp->prev;
  }
}

// Print all elements of a queue from the tail to the head.
void print_queue_reverse(Queue que) {
  nodePtr temp = que.tail;
  
  while (temp!=NULL) {
    printf("%3d ", temp->elem);
    temp = temp->next;
  }
}
