#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int b[5] = {10, 20, 30, 40, 50};
    int *bptr = &b[0];
    printf("(a) *(bptr + 3)= %d\n(b) &b[3]= %d\n(c) (b+3)= %d\n(d) bptr[1]= %d\n", *(bptr + 3), &b[3], *(b + 3), bptr[1]);
    system("pause");
    return 0;
}
//(a) *(bptr + 3),    (b) &b[3],    (c) *(b+3),    (d) bptr[1]
//D