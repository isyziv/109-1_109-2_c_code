#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char s1[100];
    char c1[100];
    printf("intput s1 ");
    fgets(s1, 100, stdin);
    printf("intput c1 ");
    scanf("%c", c1);
    size_t putf = strcspn(s1, c1);
    char fout[100];
    char *ptf = &s1[putf];
    memcpy(fout, ptf, 100);
    if (putf != strlen(s1))
    {
         puts(fout);
    }

    system("pause");
    return 0;
}