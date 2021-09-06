#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct customer
    {
        int account_number;
        char name[30];
        double balance;
    } cu[10], re[10];
    FILE *fp = fopen("random.bin", "wb");
    int i;
    if (fp == NULL)
    {
        printf("error");
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            scanf("%d%s%lf", &cu[i].account_number, cu[i].name, &cu[i].balance);
            fflush(stdin);
            fwrite(&cu[i], sizeof(struct customer), 1, fp);
        }
        fclose(fp);
    }
    kodsak return 0;
}
