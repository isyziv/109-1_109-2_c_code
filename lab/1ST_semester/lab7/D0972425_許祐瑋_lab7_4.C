#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void math()
{
    float a, b, c, d, f1, f2;
    printf("please write down a, b and c(with a - b - c)");
    scanf("%f-%f-%f", &a, &b, &c);
    d = sqrt(pow(b, 2) - 4 * a * c);
    f1 = (-b + d) / (2 * a);
    f2 = (-b - d) / (2 * a);
    printf("x=%f or %f", f1, f2);
}
int main(void)
{
    math();
    system("pause");
    return 0;
}
