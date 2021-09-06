#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int mod = 1; //0_dot____1_add
int main(void)
{
    /*
   ==========
   = Mra,Mca=
   = Mrb,Mcb=
   ==========
    */
    int Mca, Mra, Mcb, Mrb;
    srand(time(NULL));
    int tmp_a, tmp_c;
    int a[99][99];
    int b[99][99];
    printf("input matrix a size(matrix a column ,matrix a row)"); //?
    fflush(stdin);
    scanf("%d,%d", &Mca, &Mra);
    printf("input matrix b size(matrix b column ,matrix b row)"); //?
    fflush(stdin);
    scanf("%d,%d", &Mcb, &Mrb);
//ALARM CHECK
    if (Mca >= 99 || Mra >= 99 || Mcb >= 99 || Mrb >= 99)
    {
        puts(" ");
        puts("OPPOS");
        puts("Memory maybe seems to be full");
        puts("Try to use a smaller matrix");
        puts("  :( ");
        puts(" ");
        system("pause");
        return 0;
    }
    if (mod == 1)
    {
        if (Mra != Mrb || Mca != Mcb)
        {
            printf("some value maybe error");
            puts("please try again");
            system("pause");
            return 0;
        }
    }
    if (mod == 0)
    {
        if (Mra != Mcb)
        {
            printf("some value maybe error");
            puts("please try again");
            system("pause");
            return 0;
        }
    }
//OUT_PUT&COUNT    
    puts("matrix_a");

    for (int j = 0; j != Mca; j++)
    {
        for (int i = 0; i != Mra; i++)
        {
            int aaa = rand() % 4;
            aaa -= 2;
            a[j][i] = aaa;
            printf("\t%d", a[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    puts("matrix_b");
    for (int j = 0; j != Mcb; j++)
    {
        for (int i = 0; i != Mrb; i++)
        {
            int aaa = rand() % 4;
            aaa -= 2;
            b[j][i] = aaa;
            printf("\t%d", b[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    if (mod == 1)
    {
        int f[99][99];
        for (int j = 0; j != Mca; j++)
        {
            for (int i = 0; i != Mra; i++)
            {
                f[j][i] = a[j][i] + b[j][i];
            }
        }
        puts("matrix a+b");
        for (int j = 0; j != Mca; j++)
        {
            for (int i = 0; i != Mra; i++)
            {
                printf("\t%d", f[j][i]);
            }
            printf("\n");
        }
    }
    if (mod == 0)
    {
        puts("matrix a*b");
        int c;
        for (int i = 0; i < Mca; i++)
        {
            for (int j = 0; j < Mrb; j++)
            {
                c = 0;
                for (int k = 0; k < Mra; k++)
                {
                    c += a[i][k] * b[k][j];
                }
                printf("\t%d", c);
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}
