#include <stdio.h>
#include "queue_array.h"

void initialQueue(queue *que) {
  que->head = 0;
  que->tail = 0;
  que->cnt = 0;
}

int isEmpty(queue que) {
  return (que.cnt==0);
}

int head(queue que) {
  if (que.cnt>0) return que.elem[que.head];
  else {
    printf("\n  The queue is empty.\n");
    return -9999;
  }
}

void enqueue(queue *que, int e) {
  if (que->cnt<max) {
    que->elem[que->tail] = e;
    que->tail = (que->tail + 1) % max;
    que->cnt++;
  }
  else printf("  Queue overflow.\n");
}

int dequeue(queue *que) {
  int e;
  if (que->cnt>0) {
    e = que->elem[que->head];
    que->head = (que->head + 1) % max;
    que->cnt--;
    return e;
  }
  else {
    printf("  Queue underflow.\n");
    return -9999;
  }
}

void printQueue(queue que) {
  int i, h = que.head;
  
  if (que.cnt>0) {
    printf("\n  The queue elements are (from head to tail): ");
    for (i=que.cnt; i>0; i--) {
      printf("%d  ", que.elem[h]);
      h = (h + 1) % max;
    }
    printf("\n");
  }
  else printf("\n  The queue is empty.\n");
}
