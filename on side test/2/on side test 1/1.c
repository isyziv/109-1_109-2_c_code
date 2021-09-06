#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void add(int *a, int *b, int *c)
{
    scanf("%d %d", a, b);
    *c = *a + *b;
}
int main(void)
{
    int a, b, c;
    printf("input value a & b\n");
    add(&a, &b, &c);

    puts(" ");
    printf("a+b=%d", c);

    system("pause");
    return 0;
}