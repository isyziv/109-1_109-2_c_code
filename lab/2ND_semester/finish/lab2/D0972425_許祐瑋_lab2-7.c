#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void SumofArray(int **a, int length, int *re)
{
    int i, j, sum;
    sum = 0;
    for (i = 0; i < length; ++i)
    {
        for (j = 0; j < length; ++j)
        {
            //printf("%d\n",a[i][j]);
            sum += a[i][j];
        	//printf("%d\n\n",sum);}
    }
    
    *re = sum;
}

void value(int a[11][11], int length)
{
    int i, j, sum;
    for (i = 0; i < length; ++i)
    {
        for (j = 0; j < length; ++j)
        {
            a[i][j] = rand() % 300;
            printf("\t%d", a[i][j]);
        }
        puts(" ");
    }
}
int main(void)
{
    srand(time(NULL));
    int length;
    length = (rand() % 10) + 1;
    printf("%d\n", length);
    int a[11][11];
    int *p[length];
    for (int i; i < length; ++i)
    {
        p[i] = a[i];
    }
    int sum;
    int *pt = &sum;
    value(a, length);
    SumofArray(p, length, pt);
    printf("sum is %d", sum);
    puts(" ");
    system("pause");
    return 0;
}

////////////////////////////////////////////
//  int SumofArray(int a[], int length)   //
//  {                                     //
//      int i, j, sum;                    //
//      sum = 0;                          //
//      for (i = 0; i < length; ++i)      //
//          for (j = 0; j < length; ++j)  //
//              sum += a[i][j];           //
//      return sum;                       //
//  }                                     //
////////////////////////////////////////////
