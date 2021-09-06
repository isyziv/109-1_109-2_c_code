#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    unsigned d, b[10];
    scanf("%u", &d);
    int i = 1;
    for (; d != 0; i++)
    {
        b[i] = d % 2;
        d /= 2;
    }
    i <= 6 ? printf("6: 0\n") : printf("6: %u\n", b[6]);
    i <= 4 ? printf("4: 0\n") : printf("4: %u\n", b[4]);
    i <= 2 ? printf("2: 0\n") : printf("2: %u\n", b[2]);
    system("pause");
    return 0;
}