#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double a[10];
    double b;
    for (int i = 0; i != 10; i++)
    {
        b = rand();
        a[i] = b / RAND_MAX;
    }
    for (int j = 0; j != 10; j++)
    {
        printf("%d. : %1.90f\n", j, a[j]);
    }
    system("pause");
    return 0;
}
