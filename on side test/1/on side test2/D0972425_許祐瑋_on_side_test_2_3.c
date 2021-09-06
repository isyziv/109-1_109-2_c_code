#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b, c, d, n;
    a = b = c = d = n = 0;
    printf("please input N = ");
    scanf("%d", &n);
    n += 2;
    b = 1;
    a = 2;
    if (n % 2 != 0)
    {
        printf("intput error");
        system("pause");
        return 0;
    }
    do
    {
        b *= a;
        a += 2;
    } while (a != n);
    printf("%d", b);
    system("pause");
    return 0;
}