#include<stdio.h>
#include<stdlib.h>

int main(void) {
  char family_name[7], given_name[9], item[13], dollar_unit[3], item_unit[3];
  int price, amount;
  
  printf("�����G�аݧA�m����?\n");
  printf("�U�ȡG");
  scanf("%s", &family_name);
  printf("�����G%s���͡A�A�n�C�аݧA�j�W�O����?\n", family_name); 
  printf("�U�ȡG");
  scanf("%s", &given_name);
  printf("�����G%s%s���͡A�A���ѭn�R��§����?\n", family_name, given_name);
  printf("�U�ȡG");
  scanf("%s", &item);
  printf("�U�ȡG�а�%s�O�h�ֿ�?\n", item);
  printf("�����G");
  scanf("%d %s", &price, &dollar_unit);
  printf("�����G�аݧA�n�R�h��%s?\n", item);
  printf("�U�ȡG");
  scanf("%d %s", &amount, &item_unit);
  printf("�����G%s���͡A%d %s%s�`�@�O %d %s�C\n",
         family_name, amount, item_unit, item, price * amount, dollar_unit);
  printf("�U�ȡG����! �ڭn��d�C\n\n");
  
  system("pause");
  return 0;
}
