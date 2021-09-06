
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void alarm(int value, int l)
{
    //system("cls");
    puts(" ");
    system("color 40");
    printf("The value of S%d seems wrong\n Please check it again\n", value);
    puts("plese any key to continue");
    puts(" ");
    system("pause");
    //system("cls");
    system("color 07");
}
int main(void)
{

    float f;
    printf("input a float number\n");
    scanf("%f", &f);
    char s1[100], s2[100], s3[100];
    printf("input a string\n");
    fflush(stdin);
    fgets(s1, 100, stdin);
    printf("input another string\n");
    fflush(stdin);
    fgets(s2, 100, stdin);
    puts(" ");
    puts("(a)");
    puts("==========================================================");
    printf("\n f= %f\t\n\n", f);
    printf(" s1= ");
    puts(s1);
    printf(" s2= ");
    puts(s2);
    puts("==========================================================");
    system("pause");
    int n = 6;
    size_t l1 = strlen(s1);

    if (l1 <= n)
    {
        alarm(1, l1);
        n = l1 - 1;
    }

    ////////////////////////
    int n2 = 6;
    size_t l2 = strlen(s2);
    if (l2 <= n2)
    {
        alarm(2, l2);
        n2 = l2 - 1;
    }
    memcpy(s3, s1, n);
    puts(" ");
    puts("(b)");
    printf("s3 = ");
    puts(s3);
    size_t l3 = strlen(s3);
    char *cp = &s3[l3];
    memcpy(cp, s2, n2);
    n = n + n2;
    s3[n] = '\0';
    //==========================================================
    puts(" ");
    puts("(c)");
    printf("s3 = ");
    puts(s3);
    //D//////////////////////////////////
    puts(" ");
    puts("(d)");
    char s17[8], s27[8];
    memcpy(s17, s1, 7);
    memcpy(s27, s2, 7);
    printf("s1 the first 7 = ");
    puts(s17);
    printf("s2 the first 7 = ");
    puts(s27);
    if (strncmp(s17, s27, 7) == 0)
    {
        puts("s1 the first 7 = s2 the first 7");
    }
    else
    {
        puts("s1 the first 7 != s2 the first 7");
    }
    //E//
    puts(" ");
    puts("(e)");
    char e_tmp[100] = {'n', '\0'};
    size_t pute = strcspn(s1, e_tmp); //cmp
    char eout[100];
    char *pte = &s1[pute];
    memcpy(eout, pte, 100);
    if (pute != strlen(s1))
    {
        puts(eout);
        char echar[100];
        memcpy(echar, eout, 100);
        for (; strcspn(echar, e_tmp) != strlen(echar);)
        {
            size_t pute = strcspn(echar, e_tmp);
            char *ptg = &echar[pute];
            memcpy(eout, ptg, 100);
            pute++;
            ptg = &echar[pute];
            memcpy(echar, ptg, 100);
        }
        puts(eout);
    }
    else
    {
        puts("s1 doesn't contain character n");
    }

    //F//
    puts(" ");
    puts("(f)");
    char ftmp[100] = {'b', '\0'};
    size_t putf = strcspn(s2, ftmp);
    char fout[100];
    char *ptf = &s2[putf];
    int fl = l2 - putf;
    memcpy(fout, ptf, 100);
    if (putf != strlen(s2))
    {
        if (fout[1] == 'c')
        {
            puts(fout);
        }
        else
        {
            puts("s2 doesn't contain character bc");
        }
    }
    else
    {
        puts("s2 doesn't contain character bc");
    }
    //G//
    puts(" ");
    puts("(g)");
    char g[2];
    char gout[100];
    char gchar[100];

    for (int o = 0; o != strlen(s2); o++)
    {
        g[1] = '\0';
        memcpy(gchar, s1, 100);
        memcpy(g, &s2[o], 1);
        for (; strcspn(gchar, g) != strlen(gchar);)
        {
            size_t gcmp = strcspn(gchar, g);
            char *ptg = &gchar[gcmp];
            memcpy(gout, ptg, 100);
            gcmp++;
            ptg = &gchar[gcmp];
            memcpy(gchar, ptg, 100);
            puts(gout);
        }
    }

    //H//

    puts("(h)");
    char h[100];
    int hj;
    for (int hi = 0; hi != strlen(s3); hi++)
    {
        hj = 2 * hi;
        h[hj] = s3[hi];
        hj++;
        h[hj] = ' ';
    }
    hj++;
    h[hj] = '\0';
    puts(h);
    //I//
    puts(" ");
    puts("(i)");
    char ic[100];
    char i_cmp[100] = {'.', '\0'};
    sprintf(ic, "%f", f);
    size_t i_fcmp = strcspn(ic, i_cmp);
    i_fcmp += 4;
    char ifinal[100];
    memcpy(ifinal, ic, i_fcmp);
    i_fcmp++;
    ifinal[i_fcmp] = '\0';
    puts(ifinal);
    //J//err
    puts(" ");
    puts("(j)");
    int ji = 0;
    int jj = 0;
    for (ji = 0; s3[ji] != 0 && (s3[ji] > 57 || 49 > s3[ji]);)
    {
        ji++;
    }
    if (ji == strlen(s3))
    {
        printf("NO digit character");
    }
    else
    {
        printf("%d\n", ji);
    }
    //K//
    puts(" ");
    puts("(k)");
    char haystack[100], needle[100];
    printf("input haystack \n");
    fflush(stdin);
    fgets(haystack, 100, stdin);
    printf("input needle \n");
    fflush(stdin);
    fgets(needle, 100, stdin);
    printf("%s\n", strstr(haystack, needle));
    char *ptk = strstr(haystack, needle);
    puts(ptk);
    char kchar[100];
    memcpy(kchar, haystack, 100);
    int ki = 0;
    for (; strcspn(kchar, needle) != strlen(kchar);)
    {
        size_t pute = strcspn(kchar, needle);
        char *ptk = &kchar[pute];
        ptk += 2;
        memcpy(kchar, ptk, 100);
        ki++;
    }
    ki--;
    printf("%d", ki);
    system("pause");
    return 0;
}
