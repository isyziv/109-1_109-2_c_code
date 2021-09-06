#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pt(int *pa, int *pb)
{
    int *tmp;
    *tmp = *pa;
    *pa = *pb;
    *pb = *tmp;
    printf("===============\n=   s w a p   =\n===============\n");
    printf("value 1 :%d\nvalue 2 :%d\n", *pa, *pb);
}
int main(void)
{
    int a, b;
    puts("intput a value_1");
    scanf("%d", &a);
    puts("intput a value_2");
    scanf("%d", &b);
    pt(&a, &b);
    system("pause");
    return 0;
}