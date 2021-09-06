#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct frame_
{
    int a;
    char b[30];
    double c;
    double d;
};
struct frame_ frame;
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
    //fseek(data, 0, SEEK_END);
    f_end(data);
    char a[50], b[50], c[50], d[50];
    double Quantity = 0, Cost = 0;
    clr(a);
    clr(b);
    clr(c);
    clr(d);
    fflush(stdin);
    fflush(stdin);
    fflush(stdin);
    Quantity = frame.c;
    fflush(stdin);
    Cost = frame.d;
    sprintf(a, "%d", acc);
    sprintf(c, "%lf", Quantity);
    sprintf(d, "%lf", Cost);
    fwrite(a, 1, 30, data);
    fwrite(frame.b, 1, 30, data);
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
    fgets(c2, 30, data);
    char c[50];
    char d[50];
    double balance = 0;
    clr(c);
    clr(d);
    balance = frame.c;
    sprintf(c, "%lf", balance);
    balance = frame.d;
    sprintf(d, "%lf", balance);
    fseek(data, 0, SEEK_CUR);
    fwrite(" ", 1, 1, data);
    fwrite(c, 1, 30, data);
    fseek(data, 0, SEEK_CUR);
    fwrite(d, 1, 30, data);
}
void find(FILE *data)
{
    int acc = 0, re = 0;
    acc = frame.a;
    rewind(data);
    re = out(data, acc);
    re ? replace(data, acc) : alarm(data, acc);
}
void pre_data_creak(FILE *data)
{
    for (int i = 0; i != 8; i++)
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
int sign(FILE *data)
{
    int j = 0;
    if (!feof(data))
    {
        char c2[100];
        fgets(c2, 30, data);
        frame.a = atoi(c2);
        fscanf(data, "%c", c2);
        fgets(frame.b, 30, data);
        fgets(c2, 30, data);
        frame.c = atof(c2);
        fgets(c2, 30, data);
        frame.d = atof(c2);
        fseek(data, 5, SEEK_CUR);
    }
    if (!feof(data))
    {
        j = 1;
    }
    return j;
}
void Copy(FILE *b, FILE *a)
{
    char ch;
    ch = fgetc(a);
    while (!feof(a))
    {
        fprintf(b, "%c", ch);
        ch = fgetc(a);
    }
}
int main(void)
{
    FILE *data;
    FILE *data_n;
    FILE *data_1;
    data = fopen("tools", "r+");
    if (data == NULL)
    {
        puts("can't find 'tools' ");
        puts("creak new file");
        data = fopen("tools", "w");
        fprintf(data, "Tool-ID\tTool Name\tQuantity\tCost\n");
        pre_data_creak(data);
        puts("done");
        fclose(data);
        data = fopen("tools", "r+");
    }
    data_n = fopen("tools_update", "w");
    if (data_n == NULL)
    {
        puts("OPPS :(");
    }

    Copy(data_n, data);
    fclose(data);
    fclose(data_n);
    data = fopen("tools_update", "rb+");
    data_1 = fopen("tools_1", "rb+");
    if (data_1 == NULL)
    {
        puts("please run the 7_7_data_generate_edit first");
    }
    else
    {
        int i = 0;
        fseek(data_1, 33, SEEK_SET);
        i = sign(data_1);
        for (int j = 0; j != 10; j++)
        {

            find(data);
            i = sign(data_1);
        }
    }
    fclose(data_n);
    fclose(data);
    system("pause");
    return 0;
}