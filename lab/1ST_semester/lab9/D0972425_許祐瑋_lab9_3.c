#include <stdio.h>
#include <stdlib.h>

int math(int n)
{
    if (n == 0)        return 0;
    if (n == 1)        return 1;
    if (n > 1)        return math(n - 1) + math(n - 2);
}
int main(){
    int a;
    printf("Please input a positive integer:");
    scanf("%d", &a);
    printf("The value of %dth member is %d\n\n", a, math(a));
    system("pause");
    return 0;
}
