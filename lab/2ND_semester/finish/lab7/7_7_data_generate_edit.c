#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void clr(char c1[50])
{
    for (int i = 0; i != 50; i++)
    {
        c1[i] = 32;
    }
}
int out(FILE *data, int acc)
{
    char c1[100], c2[100], t1[50], t2[50], t3[50];
    clr(t1);
    fscanf(data, "%s", t1);
    fscanf(data, "%s", t1);
    fscanf(data, "%c", t1);
    fscanf(data, "%s", t1);
    fscanf(data, "%s", t1);
    fscanf(data, "%c", t1);
    fscanf(data, "%s", t1);
    fscanf(data, "%c", t1);
    fscanf(data, "%c", t1);
    for (; !feof(data);)
    {
        fgets(c1, 30, data);
        fscanf(data, "%c", t3);
        if (atoi(c1) == acc)
        {

            return 1;
        }
        fgets(c2, 30, data);
        fscanf(data, "%c", t3);
        fgets(c2, 30, data);
        fscanf(data, "%c", t3);
        fgets(c2, 30, data);
        fscanf(data, "%c", t3);
        fscanf(data, "%c", t3);
        fscanf(data, "%c", t3);
    }
    return 0;
}
void f_end(FILE *data)
{
    rewind(data);
    char t1[30];
    fscanf(data, "%s", t1);
    fscanf(data, "%s", t1);
    fscanf(data, "%s", t1);
    for (; !feof(data);)
    {
        fgets(t1, 30, data);
    }
}
void fix_fget(char c1[50])
{
    for (int i = 0; i != 50; i++)
    {
        if (c1[i] == 10)
        {
            c1[i] = 0;
            i++;
            c1[i] = 32;
        }
    }
}
void creak(FILE *data, int acc)
{
    puts("add");
    f_end(data);
    char a[50], b[50], c[50], d[50];
    double Quantity = 0, Cost = 0;
    clr(a);
    clr(b);
    clr(c);
    clr(d);
    printf("Tool-ID : %d\n", acc);
    printf("Tool Name : ");
    fflush(stdin);
    fgets(b, 30, stdin);
    fix_fget(b);
    fflush(stdin);
    printf("Quantity :");
    fflush(stdin);
    scanf("%lf", &Quantity);
    printf("Cost :");
    fflush(stdin);
    scanf("%lf", &Cost);
    sprintf(a, "%d", acc);
    sprintf(c, "%lf", Quantity);
    sprintf(d, "%lf", Cost);
    fwrite(a, 1, 30, data);
    fwrite(b, 1, 30, data);
    fwrite(c, 1, 30, data);
    fwrite(d, 1, 30, data);
    fprintf(data, "\n");
}
void alarm(FILE *data, int acc)
{
    creak(data, acc);
}
void replace(FILE *data, int acc)
{
    char c2[100];
    puts("replace");
    printf("Tool-ID : %d\n", acc);
    printf("Tool-Name : ");
    fgets(c2, 30, data);
    puts(c2);
    //fscanf(data, "%c", c2);

    char c[50];
    char d[50];
    double balance = 0;
    clr(c);
    clr(d);
    printf("Quantity : ");
    scanf("%lf", &balance);
    fflush(stdin);
    sprintf(c, "%lf", balance);

    printf("Cost : ");
    scanf("%lf", &balance);
    fflush(stdin);
    sprintf(d, "%lf", balance);
    fseek(data, 0, SEEK_CUR);
    fwrite(" ", 1, 1, data);
    fwrite(c, 1, 30, data);
    fwrite(d, 1, 30, data);
}

void find(FILE *data)
{
    int acc = 0, re = 0;
    printf("Tool-ID : ");
    scanf("%d", &acc);
    fflush(stdin);
    rewind(data);
    re = out(data, acc);
    re ? replace(data, acc) : alarm(data, acc);
}
void pre_data_create(FILE *data)
{
    for (int i; i != 8; i++)
    {
        int acc = 0;
        char a[50], b[50], c[50], d[50];
        double Quantity = 0, Cost = 0;
        clr(a);
        clr(b);
        clr(c);
        clr(d);
        if (i == 0)
        {
            acc = 3;
            Quantity = 7;
            Cost = 57.98;
            strcpy(b, "Electric Sander\0");
        }
        if (i == 1)
        {
            acc = 17;
            Quantity = 76;
            Cost = 11.99;
            strcpy(b, "Hammer\0");
        }
        if (i == 2)
        {
            acc = 24;
            Quantity = 21;
            Cost = 11.00;
            strcpy(b, "Jig Saw\0");
        }
        if (i == 3)
        {
            acc = 39;
            Quantity = 3;
            Cost = 79.5;
            strcpy(b, "Lawn Mower\0");
        }
        if (i == 4)
        {
            acc = 56;
            Quantity = 18;
            Cost = 99.99;
            strcpy(b, "Power Saw\0");
        }
        if (i == 5)
        {
            acc = 68;
            Quantity = 106;
            Cost = 6.99;
            strcpy(b, "Screwdriver\0");
        }
        if (i == 6)
        {
            acc = 77;
            Quantity = 11;
            Cost = 21.5;
            strcpy(b, "Sledge hammer\0");
        }
        if (i == 7)
        {
            acc = 83;
            Quantity = 34;
            Cost = 7.5;
            strcpy(b, "Wrench\0");
        }
        sprintf(a, "%d", acc);
        sprintf(c, "%lf", Quantity);
        sprintf(d, "%lf", Cost);
        fwrite(a, 1, 30, data);
        fwrite(b, 1, 30, data);
        fwrite(c, 1, 30, data);
        fwrite(d, 1, 30, data);
        fprintf(data, "\n");
    }
}
int main(void)
{
    FILE *data;
    data = fopen("tools_1", "rb+");
    if (data == NULL)
    {
        puts("can't find 'tools_1' ");
        puts("creak new file");
        data = fopen("tools_1", "w");
        fprintf(data, "Tool-ID\tTool Name\tQuantity\tCost\n");
        //pre_data_create(data);
        puts("done");
        fclose(data);
        data = fopen("tools_1", "rb+");
    }

    for (int i = 1; i != 10; i++)
    {
        find(data);
        /*  puts("continue?");
        puts("1:continue 0:exit");
        puts("===================");
        scanf("%d", &i);
        */
    }

    fclose(data);
    system("pause");
    return 0;
}