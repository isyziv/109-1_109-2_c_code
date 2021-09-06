#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int f_M(int *pt)
{
    int factorial = 1;
    for (int i = *pt; i > 0; i--)
    {
        factorial *= i;
    }
    return factorial;
}
int main(void)
{

    int n = 0;
    puts("input a number");
    int *pt = &n;
    scanf("%d", pt);
    printf("%d\n", f_M(pt));
    system("pause");
    return 0;
}