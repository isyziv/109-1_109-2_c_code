/* This program is to simulate a fast food restaurant system.
   The order process is as the following:
   1.  Ask and read waiter's name.
   2.  Ask and read table number.
   3.  Show the menu.
   4.  Select an item.
   5.  If the item selected is between 1 and 8, then enter the number of the selected item.
   6.  Record the order and go to Step 3.
   7.  If the item selected in Step 4 is 0, then complete the order.
   8.  List all items ordered and their quantity. 
   9.  List the total price.
   10. List the waiter's name and the table number.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char waiter[20];
  int table;
  int quantity[8];
  int i, again = 1, item, thisQuantity, total = 0;
  int price[8] = {100, 150, 180, 200, 200, 250, 50, 40};
  char *menu[8] = {"Cesar Salad   ",
                   "Hamburger     ",
                   "Cheeseburger  ",
                   "Fried Chicken ",
                   "Fried Fish    ",
                   "BBQ Rib       ",
                   "Coke          ",
                   "Milk          "};
  
  printf("**** Feng Chia Restaurant ****\n\n");
  printf("Enter waiter name: ");
  scanf("%s", &waiter);
  
  printf("Enter table number: ");
  scanf("%d", &table);
  
  for (i=0; i<8; i++) quantity[i] = 0;
  
  while (again) { 
    for (i=0; i<8; i++) {
      printf("\n%d. %s NT$ %d", i+1, menu[i], price[i]);
    }
    
    printf("\nPlease enter an item: ");
    scanf("%d", &item);    
    if (item>0 && item<9) { 
      printf("Please enter a quantity: ");
      scanf("%d", &thisQuantity);
      if (thisQuantity>0) {
        quantity[item - 1] = quantity[item - 1] + thisQuantity; }
      else {
        printf("\nThe qunatity must be greater than 0.");
      }
    }
    else if (item!=0) printf("Incorrect order.\n");
    else {again = 0;}    
  }
  
  printf("\nYour order is: \n");
  for (i=0; i<8; i++) {
    if (quantity[i] > 0) {
     printf("  %d %s\n", quantity[i], menu[i]);
     total = total + price[i] * quantity[i];
    }
  }
  printf("\nThe total charge is NT$ %d.\n", total);
  printf("Waiter: %s    Table: %d\n\n", waiter, table);
      
  system("pause");
  return 0;
}
