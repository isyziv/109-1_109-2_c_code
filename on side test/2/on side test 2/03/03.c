#include <stdio.h>
#include <stdlib.h>
unsigned ex_or(unsigned a, unsigned b)
{
    unsigned c = a ^ b;
    return c;
}
int main(void)
{
    unsigned a, b, c;
    printf("a:");
    scanf("%u", &a);
    printf("b:");
    scanf("%u", &b);
    c = ex_or(a, b);
    printf("\n%u\n", c);
    system("pause");
    return 0;
}