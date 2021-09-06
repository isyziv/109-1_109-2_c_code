#include <stdio.h>
#include <stdlib.h>
#include "students.h"

struct node {
    int       id;
    char      name[20];
    float     mterm, final;
    nodeptr   previous, next;
};

nodeptr search(nodeptr thisNode, int thisid) {
  int found = 0;

  while (thisNode != NULL && found == 0) {
    if (thisNode->id == thisid) found = 1;
    else thisNode = thisNode->next; 
  }
  if (found==0) return NULL;
  else return thisNode;
}

nodeptr swap(nodeptr node1, nodeptr node2, int sort,
             nodeptr* firstNode, nodeptr* lastNode,
             nodeptr* endNode) {

  if ((sort==1 && node1->id > node2->id) ||
      (sort==2 && strcmp(node1->name, node2->name)>0) ||
      (sort==3 && node1->mterm > node2->mterm) ||
      (sort==4 && node1->final > node2->final) ||
      (sort==5 && (node1->mterm+node1->final)/2 >
                  (node2->mterm+node2->final)/2)) {
      
    if (node1->previous!=NULL) {
      node1->previous->next = node2;
      node2->previous = node1->previous;
    }
    else { node2->previous = NULL; }
    
    if (node2->next!=NULL) {
      node2->next->previous = node1;
      node1->next = node2->next;
    }
    else { node1->next = NULL; }
    
    node1->previous = node2;
    node2->next = node1;
    if (node1 == *firstNode) *firstNode = node2;
    if (node2 == *lastNode) *lastNode = node1;
    if (node2 == *endNode) *endNode = node1;
    return node2;
  }
  else {
    return node1;
  }
}

int main(void) {
  nodeptr firstNode = NULL;
  nodeptr lastNode = NULL;
  nodeptr newNode, thisNode, endNode;
  int cmd;
  int thisid;
  int sort;
  
  while (1) {
    printf("Usage:: 1: insert, 2: delete, 3: search, 4: sort, ");
    printf("5: list, 0: exit\n");
    printf("Enter a usage command: ");
    scanf("%d", &cmd);
    printf("\n\n");
    
    switch (cmd) {
    
      case 0:
        while (firstNode != NULL) {
          thisNode = firstNode;
          firstNode = firstNode->next;
          free(thisNode);
        }
        exit (0);
        
      case 1: {
        newNode = (nodeptr) malloc(sizeof(struct node));
        printf("Enter student id: ");
        scanf("%d", &(newNode->id));
        if ((thisNode = search(firstNode, newNode->id)) == NULL) {
          printf("Enter student name: ");
          scanf("%s", &(newNode->name));
          printf("Enter midterm grade: ");
          scanf("%f", &(newNode->mterm));
          printf("Enter final exam grade: ");
          scanf("%f", &(newNode->final));
          printf("\n");
          if (lastNode!=NULL) {
            lastNode->next = newNode;
            newNode->previous = lastNode;
            newNode->next = NULL;
            lastNode = newNode;
          }
          else {
            newNode->previous = NULL;
            newNode->next = NULL;
            firstNode = newNode;
            lastNode = newNode;
          }
        }
        else {
          printf("Duplicated id number %d.\n\n", newNode->id);
          free(newNode); 
        }
        break;
      }
      
      case 2: {
        printf("Enter student id: ");
        scanf("%d", &thisid);
        thisNode = firstNode;
        if ((thisNode = search(thisNode, thisid)) != NULL) {
          if (thisNode != firstNode)
            thisNode->previous->next = thisNode->next;
          else {
            firstNode = thisNode->next;
            firstNode->previous = NULL;
          }
          
          if (thisNode != lastNode)
            thisNode->next->previous = thisNode->previous;
          else {
            lastNode = thisNode->previous;
            lastNode->next = NULL;
          }
          
          printf("Student %d has been deleted.\n\n", thisid);          
          free(thisNode);
        }
        else {
          printf("Student %d does not exist.\n\n", thisid);
        }
        break;
      }
      
      case 3: {
        printf("Enter student id: ");
        scanf("%d", &thisid);
        thisNode = firstNode;
        if ((thisNode = search(thisNode, thisid)) != NULL) {
          printf("%d  %20s  ", thisNode->id, thisNode->name);
          printf("%6.2f  %6.2f  ", thisNode->mterm, thisNode->final);
          printf("%6.2f\n\n", (thisNode->mterm+thisNode->final)/2);
        }
        else {
          printf("Student %d does not exist.\n\n", thisid);
        }
        break;
      }
      
      case 4: {
        printf("Sorting attribute:: 1: id, 2: name, 3: midterm, ");
        printf("4: final, 5: average\n");
        printf("Enter sroting attribute: ");
        scanf("%d", &sort);
        if (sort>0 && sort<6) {
          endNode = lastNode;
          thisNode = firstNode;
          while (endNode != NULL) {
            while (thisNode != endNode) {              
              thisNode = swap(thisNode, thisNode->next, sort,
                              &firstNode, &lastNode, &endNode);
              thisNode = thisNode->next;
            }
            endNode = endNode->previous;
            thisNode = firstNode;
          }
          printf("Sorting succeeds.\n\n");
        }
        else printf("Incorrect sorting attribute.\n\n");
        break;        
      }
      
      case 5: {
        thisNode = firstNode;
        while (thisNode != NULL) {
          printf("%d  %20s  ", thisNode->id, thisNode->name);
          printf("%6.2f  %6.2f  ", thisNode->mterm, thisNode->final);
          printf("%6.2f\n", (thisNode->mterm+thisNode->final)/2);
          thisNode = thisNode->next;
        }
        printf("\n");
        break;
      }
      
      default:
        break;
    }
  }
}
