// Queque application

#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

int main(void) {
  Queue q;
  int cmd, e;
  
  initial_queue(&q);
  while (1) {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print queue\n");
    printf("4. Print queue reverse\n");
    printf("5. Quit\n");
    printf("**** Enter a command: ");
    scanf("%d", &cmd);
    switch (cmd) {
      case 1: {
        printf("\nEnter an enqueued element: ");
        scanf("%d", &e);
        enqueue(&q, e);
        printf("Element %d has been enqueued.\n", e);
        break;
      }
      case 2: {
        e = dequeue(&q);
        if (e!=-9999) printf("\nElement %d has been dequeued.\n", e);
        else printf("\nThe queue is emtpy.");
        break;
      }
      case 3: {
        printf("\nThe element(s) of queue from the head to the tail are (is):\n");
        print_queue(q);
        printf("\n");
        break;
      }
      case 4: {
        printf("\nThe element(s) of queue from the tail to the head are (is):\n");
        print_queue_reverse(q);
        printf("\n");
        break;
      }
      case 5: {
        return 0;
      }
      default: printf("Incorrect command.\n");
    };
    printf("\n****************************************************\n\n");
  }
}
