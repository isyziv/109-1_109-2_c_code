#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    unsigned int number, pow;
    printf("number = ");
    scanf("%u", &number);
    printf("pow = ");
    scanf("%u", &pow);
    number <<= pow;
    printf("number*2^pow = %u\n", number);
    system("pause");
    return 0;
}