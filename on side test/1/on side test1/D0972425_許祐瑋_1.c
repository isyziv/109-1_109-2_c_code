#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a[5];
    float b;
    int w, i;
    i = 0;
    printf("input first integers ");
    scanf("%d", &a[0]);
    printf("input second integers ");
    scanf("%d", &a[1]);
    printf("input third integers ");
    scanf("%d", &a[2]);
    printf("input fourth integers ");
    scanf("%d", &a[3]);
    printf("input fifth integers ");
    scanf("%d", &a[4]);
    b = (a[0] + a[1] + a[2] + a[3] + a[4]) / 5;
    do
    {
        if (a[0] > a[1])
        {
            w = a[0];
            a[0] = a[1];
            a[1] = w;
        }
        if (a[1] > a[2])
        {
            w = a[1];
            a[1] = a[2];
            a[2] = w;
        }
        if (a[2] > a[3])
        {
            w = a[2];
            a[2] = a[3];
            a[3] = w;
        }
        if (a[3] > a[4])
        {
            w = a[3];
            a[3] = a[4];
            a[4] = w;
        }
        i++;
    } while (i != 10);
    printf("1. %d\n2. %d\n3. %d\n4. %d\n5. %d\n", a[0], a[1], a[2], a[3], a[4]);
    printf("average is %f\n", b);
    system("pause");
    return 0;
}
