#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct customer
{
    int account_number;
    char name[30];
    double balance;
} tmp;

int main(void)
{

    FILE *fp;
    fp = fopen("random.bin", "rb");
    if (fp == NULL)
    {
        printf("error");
    }
    else
    {
        int i = 0;
        printf("Account\tName\tBalance\n");
        fread(&tmp, sizeof(struct customer), 1, fp);
        for (i++; !feof(fp); i++)
        {
            printf("%d\t%s\t%lf\n", tmp.account_number, tmp.name, tmp.balance);
            fread(&tmp, sizeof(struct customer), 1, fp);
        }
        fclose(fp);
    }

    system("pause");
    return 0;
}