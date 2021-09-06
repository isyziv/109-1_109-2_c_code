#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    //a
        puts("(a)");
    printf("%-15.8u\n", 40000);
    //b//
    puts("(b)");
    int b;
    scanf("%x", &b);
    printf("%#x\n", b);
    //c/?
    puts("(c)");
    printf("sign:");
    printf("%+d", 200);
    puts(" ");
    printf("unsign:");
    printf("%u", 200);
    puts(" ");
    //d//
    puts("(d)");
    printf("%#x", 100);
    puts(" ");
    //e
    puts("(e)");
    char e[1000];
    scanf("%[^p]s", e);
    //f//err
    puts("(f)");
    printf("%8f\n", 1.234);
    //g
    puts("(g)");
    int h=0, m=0, s=0;
    fflush(stdin);
    scanf("%d%*c%d%*c%d", &h, &m, &s);
    printf("%d%d%d\n",h,m,s);
    //h
    puts("(h)");
    char hh[100];
    fflush(stdin);
    scanf("\"%[^\"]s", hh);
    printf("%s\n", hh);
    //i
    puts("(i)");
    fflush(stdin);
    scanf("%d:%d:%d", &h, &m, &s);
    printf("%d%d%d\n",h,m,s);


    system("pause");
    return 0;
}