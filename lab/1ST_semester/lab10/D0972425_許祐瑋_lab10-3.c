#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[10];
    int b;

    for (int i = 1; i <= 10; i++)
    {
        printf("NO.%d integers : ", i);
        scanf("%d", &a[i]);
    }
    for (int j = 1; j <= 10; j++)
    {
        b += a[j];
    }
    printf("%d", b);
    system("pause");
    return 0;
}
