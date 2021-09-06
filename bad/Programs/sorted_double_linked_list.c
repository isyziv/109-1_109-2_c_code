#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

int main(void) {
  list L;
  int command, key;
  
  create_list(&L); 
  while (1) {
    printf("1: Insert key to the sorted list. \n");
    printf("2: Delete key from the sorted list. \n");
    printf("3: Search key in the sorted list. \n"); 
    printf("4: Print the sorted list in the increasing order. \n"); 
    printf("5: Print the sorted list in the decreasing order. \n");
    printf("6: Stop. \n");
    printf("**** Enter a command: ");
    scanf("%d", &command);
    
    switch (command) {
      case 1: {
        printf("\nEnter an insertion key: ");
        scanf("%d", &key);
        insert_list(&L, key); 
        printf("****** %d has been inserted.\n", key); 
        break; 
      } 
      case 2: {
        printf("\nEnter a deletion key: ");
        scanf("%d", &key);
        if (delete_list(&L, key))
          printf("****** %d has been deleted.\n", key);
        else printf("****** %d is not in the sorted list.\n", key); 
        break; 
      } 
      case 3: {
        printf("\nEnter a search key: ");
        scanf("%d", &key);
        if (search_list(L, key)!=NULL)
          printf("****** %d is in the list.\n", key);
        else printf("****** %d is not in the sorted list.\n", key); 
        break; 
      } 
      case 4: {
        printf("\n****** The sorted list is in the increasing order:\n");
        print_list_increasing(L);
        printf("\n"); 
        break; 
      } 
      case 5: {
        printf("\n****** The sorted list is in the decreasing order:\n");
        print_list_decreasing(L);
        printf("\n"); 
        break; 
      } 
      case 6: {
        return 0; 
      } 
      default: {
        printf("\n****** Invalid command.\n"); 
      } 
    }
    printf("\n-------------------------------\n\n"); 
    
  }
  
  return 0;
}
