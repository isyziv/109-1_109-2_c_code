#include <stdio.h>
#include <stdlib.h>
#define segment 10 // Size of an array segment

// The data structure of a queue
typedef struct {
  int *elem;
  int head;
  int tail;
  int size; // Size of array elemenets
  int cnt; // count of queue elements
} queue;

int min(int x, int y) {
  if (x<=y) return x;
  else return y;
}

// Initialize the queueq to an empty one.
void initialQueue(queue *que) {
  que->elem = (int *) calloc(segment, sizeof(int));
  que->head = 0;
  que->tail = 0;
  que->size = segment;
  que->cnt = 0;
}

// Check emptyness of a queue.
int isEmpty(queue que) {
  return (que.cnt==0);
}

// Check the value of the head element of a queue.
int head(queue que) {
  if (que.cnt>0) return que.elem[que.head];
  else {
    printf("\n  The queue is empty.\n");
    return -9999;
  }
}

// Add an element to a queue.
void enqueue(queue *que, int e) {
  int i, j;
  
  if (que->cnt==que->size) { // The arrya of queue is full.
    // Extend the array size.
    que->size += segment;
    que->elem = (int *) realloc(que->elem, que->size * sizeof(int));
    // Move the elements from index 0 to to segment-1 or tail.
    for (i=0, j=que->size-segment; i<min(segment, que->tail); i++, j++)
      que->elem[j] = que->elem[i];
    if (que->tail>=segment) {
      // Move elements from index seqment to tail-1.
      for (i=segment; i<que->tail; i++) que->elem[i-segment] = que->elem[i];
      // Adjust que->tail.
      que->tail -= segment;
    }
    else {
      // Adjust que->tail.
      que->tail = que->size - (segment - que->tail); 
    }
  }
  // Insert element e to the queue.
  que->elem[que->tail] = e;
  que->tail = (que->tail + 1) % que->size;
  que->cnt++;
}

// Remove an element from a queue.
int dequeue(queue *que) {
  int e;
  int i, j;
  
  // Remove the head element from the queue and store it in variable e.
  if (que->cnt>0) {
    e = que->elem[que->head];
    que->head = (que->head + 1) % que->size;
    que->cnt--;
    // The size of queue element is too large. Reduce the array by a segment.
    if (que->cnt==que->size-(segment+segment/2)) { 
      if (que->head>segment/2) { // Data movement is needed.
        // The queue elements are stored in the queue in its entry order.
        if (que->head<que->tail) { 
          // Move all elements from head to tail to the beginning of the element array.
          for (i=0; i<que->tail-(que->size-segment); i++)
            que->elem[i] = que->elem[que->size-segment+i];
          que->tail = i % (que->size - segment);
        }
        // The elements are stored in the queue in the cuiculated order.
        else {
          // Preserve the elemetns from head to the end of the reduced element array.
          // Move the elements from the beginning of the element array to the end of queue
          // one segment forward.
          for (i=que->tail-1; i>=0; i--)
            que->elem[i+segment] = que->elem[i];
          // Copy the reduced array elements to the beginning of the element array.
          for (i=0; i<segment; i++)
            que->elem[i] = que->elem[que->size-segment+i];
          que->tail = (que->tail + segment) % (que->size - segment);
        }
      }
      que->size = que->size - segment;
      que->elem = (int *) realloc(que->elem, que->size * sizeof(int));
      if (que->head>=que->size) que->head = que->head - que->size;
    }
    return e;
  }
  else {
    printf("  Queue underflow.\n");
    return -9999;
  }
}

// Print the elements of a queue from head to tail
void printQueue(queue que) {
  int i, h = que.head;
  
  if (que.cnt>0) {
    printf("\n  The queue elements are (from head to tail): ");
    for (i=que.cnt; i>0; i--) {
      printf("%d  ", que.elem[h]);
      h = (h + 1) % que.size;
    }
    printf("\n");
  }
  else printf("\n  The queue is empty.\n");
}

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
        return 0;
      }
      default: printf("Incorrect command.\n");
    };
    printf("\n****************************************************\n\n");
  }
}
