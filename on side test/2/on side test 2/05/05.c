#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
FILE *data;
struct customer
{
    int account_number;
    char name[30];
    double balance;
};
struct customer tmp;
int find(int a)
{
    rewind(data);
    for (int i = 0; !feof(data); i++)
    {
        fread(&tmp, sizeof(struct customer), 1, data);
        if (tmp.account_number == a)
        {
            return i;
        }
    }
    return 0;
}
void replace(int b)
{
    puts("--------------------");
    puts("replace");
    fseek(data, b * sizeof(struct customer), SEEK_SET);
    printf("account : %d\n", tmp.account_number);
    printf("name : ");
    puts(tmp.name);
    printf("blance : ");
    scanf("%lf", &tmp.balance);
    fwrite(&tmp, sizeof(struct customer), 1, data);
}
void add()
{
    puts("--------------------");
    puts("add");
    fseek(data, 0, SEEK_END);
    printf("account : %d\n", tmp.account_number);
    printf("name : ");
    scanf("%s", tmp.name);
    printf("blance : ");
    scanf("%lf", &tmp.balance);
    fwrite(&tmp, sizeof(struct customer), 1, data);
}
void check()
{
    int a, b = 0;
    //puts("w/i");
    printf("account : ");
    scanf("%d", &a);
    b = find(a);
    tmp.account_number = a;
    b != 0 ? replace(b) : add();
}
int main()
{
    int a;
    data = fopen("customer.dat", "rb+");
    if (data == NULL)
    {
        printf("opps :(");
    }
    else
    {
        check();
    }
    fclose(data);
    system("pause");
    return 0;
}
