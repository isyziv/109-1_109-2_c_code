#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void add(int *a, int *b, int *c)
{
    *c = *a;
    *a = *b;
    *b = *c;
}
int main(void)
{
    int a, b, c;
    printf("input value a & b\n");
    scanf("%d %d", &a, &b);
    add(&a, &b, &c);

    puts(" ");
    puts("after swap");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    system("pause");
    return 0;
}