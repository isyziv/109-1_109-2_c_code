#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long a = 0;
    long *lptr = &a;
    long value_1 = 200000, value_2;
    lptr = &value_1;
    printf("%ld\n", *lptr);
    value_2 = *lptr;
    printf("%ld\n", value_2);
    printf("0X%X\n", &value_1);
    printf("0X%X\n", lptr);
    system("pause");
    return 0;
}