#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _FILE_DEFINED
struct _iobuf
{
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};
#define _FILE_DEFINED
#endif
typedef struct _iobuf file;
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
{
    if (i == 0)
    {
        data[i].account_number = 100;
        memmove(data[i].name, "Alan Jones", 30);
        data[i].balance = 348.17;
    }
    if (i == 1)
    {
        data[i].account_number = 300;
        memmove(data[i].name, "Mary Smith", 30);
        data[i].balance = 27.19;
    }
    if (i == 2)
    {
        data[i].account_number = 500;
        memmove(data[i].name, "Sam Sharp", 30);
        data[i].balance = 0.00;
    }
    if (i == 3)
    {
        data[i].account_number = 700;
        memmove(data[i].name, "Suzy Green", 30);
        data[i].balance = -14.22;
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
    file *data_s;
    data_s = fopen("bank", "w");
    fprintf(data_s, "Account\tName\tBalance\n");
    for (int i = 0; i != 10; i++)
    {
        i < 4 ? data_define(i, data_s) : data_in(i, data_s);
    }
    fclose(data_s);
    //puts("data is save");
    system("pause");
    return 0;
}