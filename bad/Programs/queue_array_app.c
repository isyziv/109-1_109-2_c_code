// Queque application

#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"

int main(void) {
  queue q;
  int cmd, e;
  
  initialQueue(&q);
  while (1) {
    printf("1. Enqueue     2. Dequeue      3. Head element\n");
    printf("4. Empty test  5. Print queue  6. Quit\n");
    printf("**** Enter a command: ");
    scanf("%d", &cmd);
    switch (cmd) {
      case 1: {
        printf("\nEnqueue operation.\n  Enter an enqueued element: ");
        scanf("%d", &e);
        enqueue(&q, e);
        break;
      }
      case 2: {
        printf("\nDequeue operation.\n");
        e = dequeue(&q);
        if (e!=-9999) printf("\n  Element %d has been dequeued.\n", e);
        break;
      }
      case 3: {
        e = head(q);
        if (e!=-9999) printf("\n  The head element is %d.\n", e);
        break;
      }
      case 4: {
        if (isEmpty(q)) printf("\n  The queue is empty.\n");
        else printf("\n  The queue is not empty.\n");
        break;
      }
      case 5: {
        printQueue(q);
        break;
      }
      case 6: {
        system("pause");
        return 0;
      }
      default: printf("Incorrect command.\n");
    };
    printf("\n****************************************************\n\n");
  }
}
