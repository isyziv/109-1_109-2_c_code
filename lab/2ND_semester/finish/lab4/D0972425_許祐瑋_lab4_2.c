#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void randvalue(int *a)
{
    for (int i = 0; i != 10; i++)
    {
        a[i] = rand() % 1000;
    }
}
int main(void)
{
    int a[10];
    int sum;
    srand(time(NULL));
    randvalue(a);
    printf("Value\tTotal Characters\n");
    for (int i = 0; i != 10; i++)
    {
        int tmp;
        printf("%d1%n", a[i], &tmp);
        printf("\t");
        sum += tmp;
        printf("%d\n", sum);
     }
    system("pause");
    return 0;
}