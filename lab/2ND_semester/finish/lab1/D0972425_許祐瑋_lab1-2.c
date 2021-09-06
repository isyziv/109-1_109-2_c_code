#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float number1 = 7.3, number2 = 0;
    float *fptr;
    fptr = &number1;
    printf("%f\n", *fptr);
    number2 = *fptr;
    printf("%f\n", number2);
    printf("0X%X\n", &number1);
    printf("0X%X\n", fptr);
    system("pause");
    return 0;
}