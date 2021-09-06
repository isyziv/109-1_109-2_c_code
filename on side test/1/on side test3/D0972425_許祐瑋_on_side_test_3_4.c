#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[5];
    for (int Z = 0; Z != 20; Z++)
    {

        for (int i = 0; i != 6; i++)
        {
            a[i] = rand() % (30 + 5 + 1) - 5;
        }
        for (int j = 1; j != 6; j++)
        {
            printf("%3.d\t", a[j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
