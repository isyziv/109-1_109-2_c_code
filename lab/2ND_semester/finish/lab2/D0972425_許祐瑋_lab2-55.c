#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *s1)
{
    char tmp;
    int n1 = 0;
    size_t n = strlen(s1);
    n -= 2;
    for (; n > n1;)
    {
        tmp = s1[n];
        s1[n] = s1[n1];
        s1[n1] = tmp;
        n--;
        n1++;
    }
}
int main(void)
{

    char s1[50];
    printf("input a string\n");
    fflush(stdin);
    fgets(s1, 50, stdin);
    swap(s1);
    puts(" ");
    puts(s1);
fflush(stdout);

    system("pause");
    return 0;
}