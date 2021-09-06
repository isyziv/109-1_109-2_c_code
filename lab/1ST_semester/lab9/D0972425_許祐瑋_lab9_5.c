
#include <stdio.h>
#include <stdlib.h>
int factorial(int x, int y)
{
    int n;
    if (y == 0)
    {
        return x;
    }

    return factorial(y, (x % y));
}
int main(void)
{
    int a, b;
    printf("input x,y =");
    scanf("%d,%d", &a, &b);
    printf("GCD=%d\n", factorial(a, b));
    system("pause");
    return 0;
}
