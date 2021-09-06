#include<stdio.h>
#include<stdlib.h>

const char *items[8] = {"�i��", "����", "�q�u��", "���ؤ�", "�����", "�d�}��", "��Q�w��", "�p���氮"};
const unsigned short prices[8] = {30, 30, 20, 25, 10, 20, 50, 35};

void reset_coins_quantities(unsigned short *coins, unsigned short *quantity) {
  int i;
  
  for (i=0; i<4; i++) coins[i] = 0;
  for (i=0; i<8; i++) quantity[i] = 0;
}

void show_transaction_state(unsigned int total_money, unsigned int total_price, unsigned short quantities[]) {
  int i; 

  printf("########################################\n");
  printf("  �ثe������A\n");
  printf("    �w��J���B�G %-3d\n", total_money);
  if (total_price>0) { 
    printf("    ��ܰӫ~�`���G %-3d\n", total_price);
    printf("    �w��ܰӫ~���ءG\n");
    for (i=0; i<8; i++) {
      if (quantities[i]>0) printf("      %s: %-2d\n", items[i], quantities[i]);
    } 
  }
  else printf("    �|����ܰӫ~\n");
  printf("########################################\n\n");
} 

char select_button(void) {
  char button; 
  
  printf("\t���s��ܡG\n");
  printf("\t  a: ��J�w��\n");
  printf("\t  b: ��ܰӫ~\n");
  printf("\t  c: �����ӫ~\n");
  printf("\t  d: �ʶR�ӫ~\n");
  printf("\t  e: �������\n");
  
  printf("\n>>> �п�ܫ��s�G "); 
  scanf("\n%c", &button);
  printf("\n"); 
  
  return button; 
}

void deposit_coins(unsigned int *total_money, unsigned int total_price, unsigned short coins[], unsigned short quantities[]) {
  unsigned int coin; 
    
  do {
    printf(">>> �Ч�J 1 ���A5 ���A10 ���ΡA50 �����w�� (��������п�J 0)�G ");     
    scanf("\n%d", &coin);
    switch (coin) {
      case 1: {coins[0] = coins[0] + 1; break;} 
      case 5: {coins[1] = coins[1] + 1; break;}
      case 10: {coins[2] = coins[2] + 1; break;}
      case 50: {coins[3] = coins[3] + 1; break;}
    }
    if (coin==1 || coin==5 || coin==10 || coin==50) {
      printf("$$$$ ��J�@�� %d ���w��\n", coin); 
      *total_money =  *total_money + coin; } 
    else  if (coin!=0) printf("$$$$ ����L��\n");
    else printf("$$$$ �������\n");
    
    printf("\n");
    show_transaction_state(*total_money, total_price, quantities);
  } while (coin != 0); 
}

void select_items(unsigned int total_money, unsigned int *total_price, unsigned short quantities[]) {
  char item;
  int i; 
  
  do {
    show_transaction_state(total_money, *total_price, quantities); 
    printf("\t�ӫ~�ﶵ�G\n"); 
    for (i=0; i<8; i++) printf("\t  %c: %s\t%d\n", 'A'+i, items[i], prices[i]);
    printf("\t  Q: �����ӫ~���\n"); 
    printf("\n>>> �п�J��ܪ��ӫ~�N���G"); 
    scanf("\n%c", &item);
    if (item>='A' && item<='H') {
    printf("**** ��ܰӫ~�G%s\n\n", items[item-'A']); 
      ++quantities[item-65];
      *total_price = *total_price + prices[item-'A'];
      }
    else if (item!='Q') printf("**** ��ܿ��~�A���W�[�ӫ~�C\n\n");
  } while (item != 'Q');
  printf("**** �����ӫ~���\n\n"); 
  show_transaction_state(total_money, *total_price, quantities); 
}

void cancel_item(unsigned int total_money, unsigned int *total_price, unsigned short quantities[]) {
  char item;
  int i; 
  
  show_transaction_state(total_money, *total_price, quantities); 
  printf("\t�ӫ~�ﶵ�G\n"); 
  for (i=0; i<8; i++) printf("\t%c: %s\t%d\n", 'A'+i, items[i], prices[i]);
  printf("\n"); 
  printf("\n>>> �п�J�������ӫ~�N���G"); 
  scanf("\n%c", &item);
  if (item>='A' && item<='H' && quantities[item-'A']>0) {
    printf("**** �����ӫ~�G%s\n\n", items[item-'A']); 
    --quantities[item-'A'];
    *total_price = *total_price - prices[item-'A'];}
  else printf("**** ��ܿ��~�A�������ӫ~�C\n\n");
  
  show_transaction_state(total_money, *total_price, quantities); 
}

void dispense_items(unsigned short quantities[]) {
  int i; 
  
  printf("**** �ʶR�ӫ~�G\n");
  for (i=0; i<8; i++)
    if (quantities[i] > 0) printf("\t%s�G %-2d\n", items[i], quantities[i]);
}

void return_changes(unsigned short changes) {
  
  printf("**** �h�^�s�� %d ���G\n", changes);
  if (changes >= 50) {printf("\t50 ���w�� %-2d ��\n", changes / 50);  changes = changes % 50; } 
  if (changes >= 10) {printf("\t10 ���w�� %-2d ��\n", changes / 10);  changes = changes % 10; } 
  if (changes >= 5)  {printf("\t 5 ���w�� %-2d ��\n", changes / 5);  changes = changes % 5; } 
  if (changes >= 1)  {printf("\t 1 ���w�� %-2d ��\n", changes); } 
  printf("\n");
} 

void return_coins(unsigned int total_money, unsigned short coins[]) {
  
  printf("**** �h�^��J�w���@ %d ���G\n", total_money);
  if (coins[3]>0) printf("\t50 ���w�� %-2d ��\n", coins[3]); 
  if (coins[2]>0) printf("\t10 ���w�� %-2d ��\n", coins[2]);
  if (coins[1]>0) printf("\t 5 ���w�� %-2d ��\n", coins[1]);
  if (coins[0]>0) printf("\t 1 ���w�� %-2d ��\n", coins[0]);
  printf("\n");
} 

void execute_transaction(void) {
  unsigned short coins[4];
  unsigned short quantities[8];
  char selected_button; 
  unsigned int total_money = 0, total_price = 0; 
  int i;
  
  reset_coins_quantities(coins, quantities);
  show_transaction_state(total_money, total_price, quantities); 
  
  do {
    selected_button = select_button();
    switch (selected_button) {
      case 'a': {
           deposit_coins(&total_money, total_price, coins, quantities);
           break; 
           }
      case 'b': {
           select_items(total_money, &total_price, quantities); 
           break;
           } 
      case 'c': {
           cancel_item(total_money, &total_price, quantities); 
           break;
           } 
      case 'd': {
           if (total_price==0) {
             printf("**** �|�����ʰӫ~�A�p�n�����Ы��u��������v�s\n\n");
             selected_button = 'c';
             show_transaction_state(total_money, total_price, quantities); 
             break; 
           } 
           if (total_money >= total_price) {
             dispense_items(quantities);
             return_changes(total_money - total_price);
             total_money = 0;
             total_price = 0;
             reset_coins_quantities(coins, quantities); 
           } 
           else {
             printf("**** ��J���B�����A���~����\n\n");
             selected_button = 'a';
             deposit_coins(&total_money, total_price, coins, quantities);} 
           break;
           } 
      case 'e': {
           if (total_money > 0) {
             printf("**** �������\n");
             return_coins(total_money, coins);
             total_money = 0;
             total_price = 0;
             reset_coins_quantities(coins, quantities); } 
           break; }
      default: {printf("@@@@@���s���~�C\n\n");} 
    }
  } while (selected_button!='d' && selected_button!='e');   
}

int main(void) {
  char transaction; 
    
  do {
    printf(">>> �p�n�~���ʶR�ӫ~�A�п�J \'Y\'�F�p�n�����ʶR�A�п�J \'N\'�G");
    scanf("\n%c", &transaction);
    printf("\n"); 
    if (transaction == 'Y') execute_transaction();
  } while (transaction != 'N'); 
  
  system("pause");
  return 0;
}
