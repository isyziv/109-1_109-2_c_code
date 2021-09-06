
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int x, y, z, w;
    x = rand();
    y = rand();
    z = rand();
    w = rand();
    puts("matrix a is");
    printf("\t%d\t%d\n\t%d\t%d\n", x, y, z, w);
    int a[2][2] = {
        {x, y},
        {z, w}};
    x = rand();
    y = rand();
    z = rand();
    w = rand();
    puts("matrix b is");
    printf("\t%d\t%d\n\t%d\t%d\n", x, y, z, w);
    int b[2][2] = {
        {x, y},
        {z, w}};
    int c[2][2];
    puts("matrix a+b =");
    c[0][0] = a[0][0] + b[0][0];
    c[0][1] = a[0][1] + b[0][1];
    c[1][0] = a[1][0] + b[1][0];
    c[1][1] = a[1][1] + b[1][1];
    printf("\t%d\t%d\n\t%d\t%d\n", c[0][0], c[0][1], c[1][0], c[1][1]);
    system("pause");
    return 0;
}