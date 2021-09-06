#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct customer
    {
        int account_number;
        char name[30];
        double balance;
    } read[10];
    FILE *fp = fopen("random.bin", "rb");
    int i;
    if (fp == NULL)
    {
        printf("error");
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            fread(&read[i], sizeof(struct customer), 1, fp);
            printf("%d %s %lf\n", read[i].account_number, read[i].name, read[i].balance);
        }
        fclose(fp);
    }
    system("pause");
    return 0;
}
