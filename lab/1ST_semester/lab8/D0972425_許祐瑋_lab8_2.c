#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void biggest(int *a, int *b, int *c, int *d, int *e)
{
    *e = *a;
    if (*e < *b)
    {
        *e = *b;
    }
    if (*e < *c)
    {
        *e = *c;
    }
    if (*e < *d)
    {
        *e = *d;
    }
}
int main(void)
{
    int a, b, c, d, e;
    printf("please input a,b,c and d\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    biggest(&a, &b, &c, &d, &e);
    printf("%d\n", e);
    system("pause");
    return 0;
}
