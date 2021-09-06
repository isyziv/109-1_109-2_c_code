#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct account
{
    int account_number;
    char name[30];
    double balance;
} data[10];
void data_storage(int i, FILE *data_s)
{
    fprintf(data_s, "%d\t", data[i].account_number);
    fprintf(data_s, "%s%c\t", data[i].name, 0);
    fprintf(data_s, "%lf", data[i].balance);
    fprintf(data_s, "\n");
}
void data_in(int i, FILE *data_s)
{
    printf("account number :");
    scanf("%d", &data[i].account_number);
    printf("name :");
    fflush(stdin);
    gets(data[i].name);
    printf("balance :");
    scanf("%lf", &data[i].balance);
    puts("==================================================================");
    data_storage(i, data_s);
}
void data_define(int i, FILE *data_s)
{ //data
    if (i == 0)
    {
        data[i].account_number = 100;
        memmove(data[i].name, "Alan Jones", 30);
        data[i].balance = 27.14;
    }
    if (i == 1)
    {
        data[i].account_number = 300;
        memmove(data[i].name, "Mary Smith", 30);
        data[i].balance = 62.11;
    }
    if (i == 2)
    {
        data[i].account_number = 300;
        memmove(data[i].name, "Mary Smith", 30);
        data[i].balance = 83.89;
    }
    if (i == 3)
    {
        data[i].account_number = 400;
        memmove(data[i].name, "John Wayne", 30);
        data[i].balance = 1000;
    }
    if (i == 4)
    {
        data[i].account_number = 700;
        memmove(data[i].name, "Suzy Green", 30);
        data[i].balance = 80.78;
    }
    if (i == 5)
    {
        data[i].account_number = 700;
        memmove(data[i].name, "Suzy Green", 30);
        data[i].balance = 1.53;
    }
    printf("account number :%d", data[i].account_number);
    puts(" ");
    printf("name :");
    puts(data[i].name);
    printf("balance :%lf", data[i].balance);
    puts(" ");
    puts("==================================================================");
    puts(" ");
    data_storage(i, data_s);
}
int main(void)
{
    FILE *data_s;
    data_s = fopen("bank_today", "w");
    fprintf(data_s, "Account\tName\tBalance\n");
    for (int i = 0; i != 6; i++)
    {
        i < 6 ? data_define(i, data_s) : data_in(i, data_s);
    }
    fclose(data_s);
    //puts("data is save");
    system("pause");
    return 0;
}