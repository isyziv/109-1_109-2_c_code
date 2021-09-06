#include <stdio.h>
#include <stdlib.h>
int N_N(int a)
{
    int b, c;
    c = (1 + a) * a / 2;
    return c;
}
int main(void)
{
    int n;
    printf("input a number ");
    scanf("%d", &n);
    printf("1 to N =%d\n", N_N(n));
    system("pause");
    return 0;
}
