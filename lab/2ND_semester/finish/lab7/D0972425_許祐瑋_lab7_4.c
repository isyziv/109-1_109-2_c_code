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

    FILE *data;
    data = fopen("random.bin", "wb");
    for (int i = 0; i != 10; i++)
    {
        printf("account ");
        fflush(stdin);
        scanf("%d", &tmp.account_number);
        printf("name ");
        fflush(stdin);
        scanf("%s", &tmp.name);
        printf("account ");
        fflush(stdin);
        scanf("%lf", &tmp.balance);
        printf("====================================\n");
        fflush(stdin);
        fflush(stdout);
        fwrite(&tmp, sizeof(struct customer), 1, data);
    }
    fclose(data);
    system("pause");
    return 0;
}