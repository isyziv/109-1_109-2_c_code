/* A restaurant has five soft drinks to serve its customer.
   The soft drinks are coded as:
     A: orange juice (@ NT$ 35),
     B: apple juice (@ NT$ 32),
     C: iced tea (@ NT$ 28),
     D: cola (@ NT$ 15),
     E: milk (@ NT$ 10). 
   A customer can order a soft drink with a given quantity.
   Read an order of a soft drink code and quantity.
   Then, print the kind of soft drink, the number of order, and the total price.
*/

#include <stdio.h>

int main(void) {
  
  char kind;
  int quantity;
  
  printf("Enter the code of a soft drink: ");
  scanf("%c", &kind);
  printf("Enter the quantity of the order: ");
  scanf("%d", &quantity);
  
  switch (kind) {
    case 'A': {
      printf("\nOrange juice, %d orders: NT$ %d\n\n", quantity, quantity*35);
      break;
    }
    case 'B': {
      printf("\nApple juice, %d orders: NT$ %d\n\n", quantity, quantity*32);
      break;
    }
    case 'C': {
      printf("\nIced tea, %d orders: NT$ %d\n\n", quantity, quantity*28);
      break;
    }
    case 'D': {
      printf("\nCola, %d orders: NT$ %d\n\n", quantity, quantity*15);
      break;
    }
    case 'E': {
      printf("\nMilk, %d orders: NT$ %d\n\n", quantity, quantity*10);
      break;
    }
    default: printf("\nNo such drinks available.\n\n");
  }
  
  system("pause");
  return 0; 
}
