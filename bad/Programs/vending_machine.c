#include<stdio.h>
#include<stdlib.h>

const char *items[8] = {"可樂", "雪碧", "礦泉水", "茶裏王", "科學麵", "卡迪那", "阿Q泡麵", "小熊餅乾"};
const unsigned short prices[8] = {30, 30, 20, 25, 10, 20, 50, 35};

void reset_coins_quantities(unsigned short *coins, unsigned short *quantity) {
  int i;
  
  for (i=0; i<4; i++) coins[i] = 0;
  for (i=0; i<8; i++) quantity[i] = 0;
}

void show_transaction_state(unsigned int total_money, unsigned int total_price, unsigned short quantities[]) {
  int i; 

  printf("########################################\n");
  printf("  目前交易狀態\n");
  printf("    已投入金額： %-3d\n", total_money);
  if (total_price>0) { 
    printf("    選擇商品總價： %-3d\n", total_price);
    printf("    已選擇商品項目：\n");
    for (i=0; i<8; i++) {
      if (quantities[i]>0) printf("      %s: %-2d\n", items[i], quantities[i]);
    } 
  }
  else printf("    尚未選擇商品\n");
  printf("########################################\n\n");
} 

char select_button(void) {
  char button; 
  
  printf("\t按鈕選擇：\n");
  printf("\t  a: 投入硬幣\n");
  printf("\t  b: 選擇商品\n");
  printf("\t  c: 取消商品\n");
  printf("\t  d: 購買商品\n");
  printf("\t  e: 取消交易\n");
  
  printf("\n>>> 請選擇按鈕： "); 
  scanf("\n%c", &button);
  printf("\n"); 
  
  return button; 
}

void deposit_coins(unsigned int *total_money, unsigned int total_price, unsigned short coins[], unsigned short quantities[]) {
  unsigned int coin; 
    
  do {
    printf(">>> 請投入 1 元，5 元，10 元或，50 元的硬幣 (投幣完成請輸入 0)： ");     
    scanf("\n%d", &coin);
    switch (coin) {
      case 1: {coins[0] = coins[0] + 1; break;} 
      case 5: {coins[1] = coins[1] + 1; break;}
      case 10: {coins[2] = coins[2] + 1; break;}
      case 50: {coins[3] = coins[3] + 1; break;}
    }
    if (coin==1 || coin==5 || coin==10 || coin==50) {
      printf("$$$$ 投入一個 %d 元硬幣\n", coin); 
      *total_money =  *total_money + coin; } 
    else  if (coin!=0) printf("$$$$ 投幣無效\n");
    else printf("$$$$ 投幣結束\n");
    
    printf("\n");
    show_transaction_state(*total_money, total_price, quantities);
  } while (coin != 0); 
}

void select_items(unsigned int total_money, unsigned int *total_price, unsigned short quantities[]) {
  char item;
  int i; 
  
  do {
    show_transaction_state(total_money, *total_price, quantities); 
    printf("\t商品選項：\n"); 
    for (i=0; i<8; i++) printf("\t  %c: %s\t%d\n", 'A'+i, items[i], prices[i]);
    printf("\t  Q: 結束商品選擇\n"); 
    printf("\n>>> 請輸入選擇的商品代號："); 
    scanf("\n%c", &item);
    if (item>='A' && item<='H') {
    printf("**** 選擇商品：%s\n\n", items[item-'A']); 
      ++quantities[item-65];
      *total_price = *total_price + prices[item-'A'];
      }
    else if (item!='Q') printf("**** 選擇錯誤，未增加商品。\n\n");
  } while (item != 'Q');
  printf("**** 結束商品選擇\n\n"); 
  show_transaction_state(total_money, *total_price, quantities); 
}

void cancel_item(unsigned int total_money, unsigned int *total_price, unsigned short quantities[]) {
  char item;
  int i; 
  
  show_transaction_state(total_money, *total_price, quantities); 
  printf("\t商品選項：\n"); 
  for (i=0; i<8; i++) printf("\t%c: %s\t%d\n", 'A'+i, items[i], prices[i]);
  printf("\n"); 
  printf("\n>>> 請輸入取消的商品代號："); 
  scanf("\n%c", &item);
  if (item>='A' && item<='H' && quantities[item-'A']>0) {
    printf("**** 取消商品：%s\n\n", items[item-'A']); 
    --quantities[item-'A'];
    *total_price = *total_price - prices[item-'A'];}
  else printf("**** 選擇錯誤，未取消商品。\n\n");
  
  show_transaction_state(total_money, *total_price, quantities); 
}

void dispense_items(unsigned short quantities[]) {
  int i; 
  
  printf("**** 購買商品：\n");
  for (i=0; i<8; i++)
    if (quantities[i] > 0) printf("\t%s： %-2d\n", items[i], quantities[i]);
}

void return_changes(unsigned short changes) {
  
  printf("**** 退回零錢 %d 元：\n", changes);
  if (changes >= 50) {printf("\t50 元硬幣 %-2d 個\n", changes / 50);  changes = changes % 50; } 
  if (changes >= 10) {printf("\t10 元硬幣 %-2d 個\n", changes / 10);  changes = changes % 10; } 
  if (changes >= 5)  {printf("\t 5 元硬幣 %-2d 個\n", changes / 5);  changes = changes % 5; } 
  if (changes >= 1)  {printf("\t 1 元硬幣 %-2d 個\n", changes); } 
  printf("\n");
} 

void return_coins(unsigned int total_money, unsigned short coins[]) {
  
  printf("**** 退回投入硬幣共 %d 元：\n", total_money);
  if (coins[3]>0) printf("\t50 元硬幣 %-2d 個\n", coins[3]); 
  if (coins[2]>0) printf("\t10 元硬幣 %-2d 個\n", coins[2]);
  if (coins[1]>0) printf("\t 5 元硬幣 %-2d 個\n", coins[1]);
  if (coins[0]>0) printf("\t 1 元硬幣 %-2d 個\n", coins[0]);
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
             printf("**** 尚未選購商品，如要取消請按「取消交易」鈕\n\n");
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
             printf("**** 投入金額不足，請繼續投幣\n\n");
             selected_button = 'a';
             deposit_coins(&total_money, total_price, coins, quantities);} 
           break;
           } 
      case 'e': {
           if (total_money > 0) {
             printf("**** 取消交易\n");
             return_coins(total_money, coins);
             total_money = 0;
             total_price = 0;
             reset_coins_quantities(coins, quantities); } 
           break; }
      default: {printf("@@@@@按鈕錯誤。\n\n");} 
    }
  } while (selected_button!='d' && selected_button!='e');   
}

int main(void) {
  char transaction; 
    
  do {
    printf(">>> 如要繼續購買商品，請輸入 \'Y\'；如要停止購買，請輸入 \'N\'：");
    scanf("\n%c", &transaction);
    printf("\n"); 
    if (transaction == 'Y') execute_transaction();
  } while (transaction != 'N'); 
  
  system("pause");
  return 0;
}
