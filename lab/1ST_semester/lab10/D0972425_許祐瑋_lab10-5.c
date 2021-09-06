#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[12];

    for (int i = 1; i <= 10; i++)
    {
        printf("NO.%d integers : ", i);
        scanf("%d", &a[i]);
    }

    for (int j = 1; j <= 10; j++)
    {
        if (j == 10)
        {
            a[11] = a[1];
        }
        a[j] += a[j + 1];

        printf("%d. %d\n", j, a[j]);
    }

    printf("\n");
    system("pause");
    return 0;
}
