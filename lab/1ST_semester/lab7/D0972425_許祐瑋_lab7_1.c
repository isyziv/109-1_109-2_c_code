#include <stdio.h>
#include <stdlib.h>
int N_N(int);
int main(void)
{
    int n;
    printf("input a number ");
    scanf("%d", &n);
    printf("N!=%d\n", N_N(n));
    system("pause");
    return 0;
}
int N_N(int a)
{
    int b, c;
    b = c = 1;
    do
    {
        b++;
        c = b * c;
    } while (b != a);
    return c;
}
