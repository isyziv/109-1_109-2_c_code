#include <stdio.h>
#include <stdlib.h>
#include "students.h"

// struct node is the data structure for student's record.
// nodeptr is a data type of pointer to node.
struct node {
    int       id;
    char      name[20];
    float     mterm, final;
    nodeptr   previous, next;
};


nodeptr search(nodeptr thisNode, int thisid) 
// Search operation.
//
// Search thisid starting from the node pointed by thisNode.
//
// If the search succeeds (found!=0), returns nodeptr pointing
// to the node with thisid.
//
// If the search fails (found==0), returns the NULL pointer.
{
  int found = 0; // At the beginning, assume thisid is not found.
  
// Iterate until the end of list or
// thisid is found in the node pointed by thisNode.

}

nodeptr compareAndSwap(nodeptr node1, nodeptr node2, int sort,
             nodeptr* firstNode, nodeptr* lastNode,
             nodeptr* endNode) 
// Compare and swap operation.
//
// The first two parameters, node1 and node2, are the pointers of two
// neighboring nodes, where node1 points to the first node and node2 points
// to the second node.
//
// Parameter sort indicates the field to be sorted.
//    1. id, 2. name, 3. mterm, 4. final, 5. average (i.e., (mterm+final)/2)
//
// The last three parameters are pointers pointing to firstNode, lastNode, and
// endNode, respectively. These three parameters are pass-by-reference parameters.
// They are passed to compareAndSwap because we must maintain firstNode, lastNode,
// and endNode, if any of them is involved in the swap operation.
//
// Fucntion compareAndSwap returns nodeptr pointing to the node which becomes 
// the first node at the end of the function call.
{
  if (
       // Compare condition. Check the sorted field and whether 
       // the corresponding data is out of order
     )
  {
    //
    // The sorted fields are out of order and the two nodes are swapped.
    //
    // Update the following six pointers: 
    //   node1->previous->next, node2->previous,
    //   node2->next->previous, node1->next, 
    //   node1->previous, node2->next.
    // 
    // You need to consider two marginal cases:
    //   1. when node1->previous==NULL, i.e., node1 is firstNode. In this case,
    //      simply set node2->previous to NULL.
    //   2. when node2->next==NULL, i.e., node2 is lastNode. In this case,
    //      simply set node1->next to NULL.
    //
    // Maintaining firstNode, lastNode, and endNode:
    //   1. if node1 and firstNode are the same, set firstNode to node2.
    //   2. if node2 and lastNode are the same, set lastNode to node1.
    //   3. if node2 and endNode are the same, set endNode to node1.
    //
    // At the end of swap operation, the second node is returned.
  }
  else {
    // 
    // The sorted fields are not out of order and the two nodes are not swapped. 
    // Hence, the first node is returned.
  }
}

int main(void) {
  nodeptr firstNode = NULL; // The double-linked list is empty, initially.
  nodeptr lastNode = NULL; // The double-linked list is empty, initially.
  nodeptr newNode; // Pointing to a new node to be inserted.
  nodeptr thisNode; // Pointing to a node to be processed.
  nodeptr endNode; // Pointing to a node at the end of a node segment duing the
                   // sorting operation.
  int cmd; // Usage command.
  int thisid; // Student id that is going to be searched for.
  int sort; // Sorting field.
  
  // The main routine is an infinite loop. The loop terminates if the user enters
  // "0" command.
  while (1) {
    printf("Usage:: 1: insert, 2: delete, 3: search, 4: sort, ");
    printf("5: list, 0: exit\n");
    printf("Enter a usage command: ");
    scanf("%d", &cmd);
    printf("\n\n");
    
    switch (cmd) {
    
      case 0: {
        // EXIT command.
        // Make sure to free all nodes. Then, exit from the program.
      }
        
      case 1: {
        // INSERT command.
        // Create a new node and set newNode pointing to this newly created node.
        newNode = (nodeptr) malloc(sizeof(struct node));
        
        // Read student id.
        printf("Enter student id: ");
        scanf("%d", &(newNode->id));
        
        // If student id does not exist, proceed the insert operation,
        // otherwise, not to insert newNode.
        if ( 
             // Codition check whether student id exists or not.
             // Use "search" function.
           )
        {
          // The case when student id is not found.
          // Continue to read other data fields: name, mterm, final.
          printf("Enter student name: ");
          scanf("%s", &(newNode->name));
          printf("Enter midterm grade: ");
          scanf("%f", &(newNode->mterm));
          printf("Enter final exam grade: ");
          scanf("%f", &(newNode->final));
          printf("\n");
          
          // Insertion is processed here.
          // You must consider the case whether lastNode is empty or not.
          //   1. If lastNode is not empty, append the node pointed by newNode to
          //      the end of the list, i.e., update lastNode.
          //      In this case you need to modify newNode
          //   2. If lastNode is empty, the double-linked list is also empty and
          //      the node pointed by newNode is also the first node of the list. 
          //      That is, update both firstNode and lastNode.
        }
        else {
          // Student id is duplicated. Insertion operation fails.
          //
          // Remember to free newNode.
        }
        break;
      }
      
      case 2: {
        // DELETE command.
        // Read the student id to be deleted.
        printf("Enter student id: ");
        scanf("%d", &thisid);
        //
        // Search thisid in the double-linked list starting from firstNode.
        if (
             // Codition check whether thisid exists or not.
             // Use "search" function.
            )
        {
          // If thisid exists, the node to be deleted should be pointed 
          // by thisNode.
          //
          // Update thisNode->previous->next and thisNode->next->previous.
          // When deleting a node, you must consider if the deleted node 
          // is firstNode or lastNode.
          //
          // Remember to free the deleted node.
        }
        else {
          // Student id does not exist. Delete operation fails. 
        }
        break;
      }
      
      case 3: {
        // SEARCH command.
        // Read the student to be searched.
        printf("Enter student id: ");
        scanf("%d", &thisid);
        //
        // Search thisid in the double-linked list starting from firstNode.
        if (
             // Codition check whether thisid exists or not.
             // Use "search" function.
           )
        {
          // Search succeeds. Print student's data.
        }
        else {
          // Search operation failes. Print an error message.
        }
        break;
      }
      
      case 4: {
        // SORT command.
        // Read the sorting field.
        printf("Sorting field:: 1: id, 2: name, 3: midterm, ");
        printf("4: final, 5: average\n");
        printf("Enter sroting attribute: ");
        scanf("%d", &sort);
        
        if (sort>0 && sort<6)
        {
          // If the sorting field is valid. Proceed the sorting operation.
          //
          // Bubble sort is used to perform the sorting operation.
          //   1. The outer loop iterates on a segment of double-linked list,
          //      starting from firstNode and ending at endNode.
          //   2. At the first iteration, the segment is the entire list. i.e.,
          //      endNode is set to be lastNode.
          //   3. Use thisNode to recall the current node to be processed.
          while (
                 // Checke termination condition, i.e., terminate the loop 
                 // if the segment to be processed is empty.
                )
          {
            // 1. The inner loop iterates each element of the segment ending at
            //    endNode.
            // 2. Two neighboring nodes are compared and swapped.
            while (
                   // Suppose the current node is pointed by thisNode.
                   // Checke termination condition, i.e., thisNode reaches
                   // the end of segment.
                  ) 
            {
              // Use function compareAndSwap to comapre and swap two neighboring
              // nodes, i.e., the nodes pointed by thisNode and thisNode->next.
              //   1. Note that, if thisNode has not reached the end of segment, 
              //      its next node must exist.
              //   2. Remember to pass the sorting field, and three pointers,
              //      firstNode, lastNode, and endNode (all pass-by-reference),
              //      that must be maintained in function compareAndSwap.
              //   3. Remember that function compareAndSwap returns the pointer 
              //      to the first node. Store it in thisNode!
              //
              // Continue the loop to the next node of thisNode.
            } // end of inner loop
            //
            // After completion of an iteration of the outer loop, update
            // the list segment.
            //   1. Set endNode to be endNode->previous.
            //   2. Reset thisNode to the beginning of the entire list.
          } // end of outer loop
          //
          // End of bubble sort. Sort succeeds.
        }
        else 
        {
          // Invalid sorting field.
        }
        break;        
      }
      
      case 5: {
        // LIST command.
        // Print all student data starting from the first node in the list
        // to the last node.
        }
        break;
      }
      
      default: {
        // Invalid command. Do nothing.
        break;
      } 
    } // end of switch statement
  } // end of while loop
} // end of main program
