#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j;
    i = j = 0;
    while (i != 300)
    {
        i = i + 3;
        j = j + i;
    }

    printf("%d\n", j);
    system("pause");
    return 0;
}