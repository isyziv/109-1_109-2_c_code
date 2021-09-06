#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b, n;
    printf("please input N = ");
    scanf("%d", &n);
    a = b = 0;
    for (a = 0; n != a; a++)
    {
        if (a % 2 != 0)
        {
            b = b + a;
        }
    }
    printf("%d", b);
    system("pause");
    return 0;
}