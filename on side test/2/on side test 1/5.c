
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    char s22[100];
    memcpy(s22, s2, 6);
    char s3[100];
    strcat(s1, s22);
    puts(s1);
    system("pause");
    return 0;
}