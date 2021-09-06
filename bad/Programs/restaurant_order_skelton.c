#include <stdio.h>

int main(void) {
  int i, again = 1, item, thisQuantity, total = 0;
  int price[6] = {100, 150, 200, 200, 250, 40}; // Set price of all menu items.
  int quantity[6] = {0,0,0,0,0,0}; // Set initial quantity of all menu items to 0.
  char *menu[6] = {"Cesar Salad   ",
                   "Hamburg       ",
                   "Fried Chicken ",
                   "Fried Fish    ",
                   "BBQ Rib       ",
                   "Coke          "}; // Set name of all menu items.
  
  while (again) { 
    for (i = 0; i < 6; i++) {
      // Print the i-th menu item and its price.
      // Note that the index of the printed line is one greater than the value of the loop variable.
    }
    
    printf("\nPlease enter an item: ");
    scanf("%d", &item);    
    if (item > 0 && item < 7) {
      // If the item number is 1, 2, 3, 4, 5, or 6, input the quantity of the item being ordered.
      // You may want to check whether the quantity is a positive integer or not.
      // If the quantity is a positive, accumulate the quantity of the selected item;
      // otherwise, show a warning message.
    }
    else {
      // If the item number is any number other than 1, 2, 3, 4, 5, and 6, the order is completed.
      // Think of how to terminate the while loop.
    }    
  }
  
  printf("\nYour order is: \n");
  for (i = 0; i < 6; i++) {
    // Compute the total price.
    // Don't print a line if the quantity of an item is zero.
  }
  printf("\nThe total charge is %d.\n", total);
      
  exit(1);
}
