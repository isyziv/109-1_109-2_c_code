#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int math()
{
    int x, y, z, r;
    printf("x =");
    scanf("%d", &x);
    printf("y =");
    scanf("%d", &y);
    printf("z =");
    scanf("%d", &z);
    r = z;
    if (x <= y)
    {
        if (y <= z)
        {
            r = y;
        }
        else if (x <= z)
        {
            r = z;
        }
        else
        {
            r = x;
        }
    }
    if (z <= y)
    {
        r = y;
    }
    if (x <= z)
    {
        r = x;
    }
    return r;
}
int main(void)
{
    printf("%d", math());
    system("pause");
    return 0;
}
