#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>

#include <stdlib.h>
int main(void)
{
    int a[10];
    int b, c;
    b = c = 0;
    for (int i = 1; i <= 10; i++)
    {
        a[i] = rand();
        printf("NO.%d integers : %d\n", i, a[i]);
    }
    for (int j = 1; j <= 10; j++)
    {
        if (b < a[j])
        {
            b = a[j];
        }
    }
    printf("the biggest is %d", b);
    c = b;
    for (int j = 1; j <= 10; j++)
    {
        if (c > a[j])
        {
            c = a[j];
        }
    }
    printf("the smallest is %d", c);

    printf("\n");
    system("pause");
    return 0;
}
