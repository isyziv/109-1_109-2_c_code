#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pt()
{
    int a, b;
    int *pt_a, *pt_b;
    puts("intput a value_1");
    scanf("%d", &a);
    puts("intput a value_2");
    scanf("%d", &b);
    pt_a = &a;
    pt_b = &b;
    int re;
    re = *pt_a + *pt_b;
    return re;
}
int main(void)
{
    printf("%d\n", pt());
    system("pause");
    return 0;
}