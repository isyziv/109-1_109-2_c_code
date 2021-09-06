#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct employee
{
    int id;
    char lastName[30];
    char firstName[30];
    char gender[30];
    int age;
    float salary;
} tmp[10];

int main(void)
{

    FILE *fp;
    //fp = fopen("customer.dat", "rb");
    fp = fopen("employee.dat", "rb");
    if (fp == NULL)
    {
        printf("error");
    }
    else
    {
        printf("Account\tName\tBalance\n");
        for (int i = 0; i < 10; i++)
        {
            fread(&tmp[i], sizeof(struct employee), 1, fp);
            printf("%d\t%s\t%lf\n", tmp[i].id, tmp[i].lastName, tmp[i].salary);
        }
        fclose(fp);
    }

    system("pause");
    return 0;
}