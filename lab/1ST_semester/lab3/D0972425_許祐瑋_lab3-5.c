#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    float a , b;
    scanf("%f" ,&a);
    b = (pow(a, 3) - 2 * pow(a, 2) + 10 * a - 5)/(a-10);
    printf("%f" ,b);
    system("pause");
    return 0;
}
