#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char elem;
  struct Node* left;
  struct Node* right;
} node;

typedef struct Double_List {
  node* tail;
  node* head;
} dlist;

void initial_list(dlist *L) {
  L->tail = NULL;
  L->head = NULL;
}
     
// Insert a node to the tail.
void add_to_tail (dlist *L, char C) {
  node* temp;
  
  temp = (node*) malloc(sizeof(struct Node));
  temp->elem = C;
  temp->left = NULL;
  if (L->tail == NULL) {
    temp->right = NULL;
    L->tail = temp;
    L->head = temp;
  }
  else {
    temp->right = L->tail;
    L->tail->left = temp;
    L->tail = temp;
  }
}

// Remove a node from the tail.
void remove_from_tail (dlist *L) {
  node* temp;
  char C;
  
  if (L->tail!=NULL) {
    temp = L->tail;
    C = temp->elem;
    if (temp->right==NULL) {
      L->tail = NULL;
      L->head = NULL;
    }
    else {
      L->tail = temp->right;
      L->tail->left = NULL;
    }    
    free(temp);
  }
}

// Remove a node from the head.
void remove_from_head (dlist *L) {
  node* temp;
  char C;
  
  if (L->head!=NULL) {
    temp = L->head;
    C = temp->elem;
    if (temp->left==NULL) {
      L->tail = NULL;
      L->head = NULL;
    }
    else {
      L->head = temp->left;
      L->head->right = NULL;
    }    
    free(temp);
  }
}

int main(void) {
  dlist lst;
  char str[1000];
  int i;
  
  while (1) {
    initial_list(&lst);
    printf("Enter a string: ");
    scanf("%s", str);
    if (strcmp(str, "000")==0) return 0;
    i = 0;
    while (str[i]!='\0') add_to_tail(&lst, str[i++]);
    while (lst.head!=lst.tail && lst.head->elem==lst.tail->elem) {
      remove_from_head(&lst);
      remove_from_tail(&lst);
    }
    if (lst.head==lst.tail) printf("\n\"%s\" is a palindrome.\n\n", str);
    else  printf("\n\"%s\" is not a palindrome.\n\n", str);
    while (lst.head!=NULL) remove_from_head(&lst);
    printf("**************************************************************\n\n");
  }
}
