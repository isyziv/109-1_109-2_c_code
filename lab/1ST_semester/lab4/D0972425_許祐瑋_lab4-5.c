#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b, c, d;
    printf("integer =");
    scanf("%d", &a);
    b = a % 2;
    c = a % 3;
    d = a % 5;
    if (b == 0)
    {
        printf("integer is multiple of 2\n");
    }
    if (c == 0)
    {
        printf("integer is multiple of 3\n");
    }
    if (d == 0)
    {
        printf("integer is multiple of 5\n");
    }
    system("pause");
    return 0;
}