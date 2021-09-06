#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char h[100], s3[100];
    fgets(s3, 100, stdin);
    int hj;
    for (int hi = 0; hi != strlen(s3); hi++)
    {
        hj = 2 * hi;
        h[hj] = s3[hi];
        hj++;
        h[hj] = ' ';
    }
    hj++;
    h[hj] = '\0';
    puts(h);
    system("pause");
    return 0;
}