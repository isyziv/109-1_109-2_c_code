#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    srand(time(NULL));
    int n;
    n = rand()%10;
    int a[100], b[100];
    long long f;
    printf("arry a {");
    for (int m = 0; m != n;m++)
    {
        a[m] = rand();
        printf(" %d,",a[m]);
    }
    printf("}");
    puts(" ");
        printf("arry b {");
    for (int m = 0; m != n;m++)
    {
        b[m] = rand();
        printf(" %d,",a[m]);
    }
    printf("}");
        for (int m = 0; m != n;m++)
    {
        int c;
        c=a[m]*b[m];
        f += (long long)c;
    }
    puts(" ");
printf("a+b=%lld",f);
puts(" ");
system("pause");
    return 0;
}