#include<stdio.h>
#include<stdlib.h>

int main(void) {
  char family_name[7], given_name[9], item[13], dollar_unit[3], item_unit[3];
  int price, amount;
  
  printf("店員：請問你姓什麼?\n");
  printf("顧客：");
  scanf("%s", &family_name);
  printf("店員：%s先生，你好。請問你大名是什麼?\n", family_name); 
  printf("顧客：");
  scanf("%s", &given_name);
  printf("店員：%s%s先生，你今天要買什禮物嗎?\n", family_name, given_name);
  printf("顧客：");
  scanf("%s", &item);
  printf("顧客：請問%s是多少錢?\n", item);
  printf("店員：");
  scanf("%d %s", &price, &dollar_unit);
  printf("店員：請問你要買多少%s?\n", item);
  printf("顧客：");
  scanf("%d %s", &amount, &item_unit);
  printf("店員：%s先生，%d %s%s總共是 %d %s。\n",
         family_name, amount, item_unit, item, price * amount, dollar_unit);
  printf("顧客：謝謝! 我要刷卡。\n\n");
  
  system("pause");
  return 0;
}
