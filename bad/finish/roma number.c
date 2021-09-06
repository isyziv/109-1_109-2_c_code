#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int a;
    char romadoman[6];

    int vlaue[10];
    scanf("%d", &a);
    for (int i = 0; a != 0; i++)
    {
        vlaue[i] = a % 10;
        a /= 10;
    }
    memcpy(romadoman, "ivxcdm", 6);

    system("pause");
    return 0;
}