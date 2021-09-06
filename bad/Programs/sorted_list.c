#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"

int main(void) {
  list L;
  int command, key;
  
  create_list(&L); 
  while (1) {
    printf("1: Insert key to the sorted list. \n");
    printf("2: Delete key from the sorted list. \n");
    printf("3: Search key in the sorted list. \n"); 
    printf("4: Print the sorted list. \n");
    printf("5: Stop. \n");
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
        if (search_list(L, key))
          printf("****** %d is in the list.\n", key);
        else printf("****** %d is not in the sorted list.\n", key); 
        break; 
      } 
      case 4: {
        printf("\n****** The sorted list is:\n");
        print_list(L);
        printf("\n"); 
        break; 
      } 
      case 5: {
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
