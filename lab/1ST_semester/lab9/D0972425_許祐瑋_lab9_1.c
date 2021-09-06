#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int factorial(num)
{
    if (num == 1)
    {
        return num;
    }
    else
    {
        return num * factorial(num - 1);
    }
}
int main(void)
{
    int n;
    printf("input N =");
    scanf("%d", &n);
    printf("%d\n",factorial(n));
    system("pause");
    return 0;
}
