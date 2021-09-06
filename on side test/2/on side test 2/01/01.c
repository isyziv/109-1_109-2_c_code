#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct v
{
    int fraction;
    int denominator;
};
typedef struct v var;
int gcd(int m, int n)
{
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
void math(var *a, var *b, var *c)
{
    int under, fa, div;
    under = a->denominator * b->denominator;
    fa = (a->fraction * b->denominator) - (b->fraction * a->denominator);
    div = gcd(under, fa);
    c->fraction = fa / div;
    c->denominator = under / div;
}
void out(var c)
{
    puts(" ");
    puts("==================");
    printf("%d/%d", c.fraction, c.denominator);
}
int main(void)
{
    var a;
    var b;
    var c;
    printf("please enter the first fraction( a/b ) :");
    scanf("%d/%d", &a.fraction, &a.denominator);
    printf("please enter the second fraction( a/b ) :");
    scanf("%d/%d", &b.fraction, &b.denominator);
    math(&a, &b, &c);
    out(c);
    system("pause");
    return 0;
}