#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a;
    int c;
    int b = 0;
    int d = 0;
    bool x;
    printf("please input a integers ");
    scanf("%d", &a);
    c = a;
    if (a % 2 == 0)
    {
        printf("a is even\n");
    }
    else
    {
        printf("a is not even\n");
    }
    if (a % 7 == 0)
    {
        printf("a is multiple of 7\n");
    }
    else
    {
        printf("a is not a multiple of 7\n");
    }
    x = (c <= 3) || b;
    while (x == 0)
    {

        c--;
        d = a % c;
        if (d == 0)
        {
            b = 1;
        }
        x = (c <= 3) || b;
    }

    if (b == 1)
    {
        printf("%d is not a Prime number\n", a);
    }
    if (b == 0)
    {
        printf("%d is a Prime number\n", a);
    }

    system("pause");
    return 0;
}
