#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b;
    float product_sell[5];
    float price[5];
    float c, total_peice;
    int d;
    d = 0;
    total_peice = 0;
    product_sell[0] = 0;
    product_sell[1] = 0;
    product_sell[2] = 0;
    product_sell[3] = 0;
    product_sell[4] = 0;
    price[0] = 2.98;
    price[1] = 4.5;
    price[2] = 9.98;
    price[3] = 4.49;
    price[4] = 6.87;
    printf("please input product number and Quantity sold\n");
    printf("Follow the a-b rule to enter\n");
    printf("if want to exit please type 0-0\n");
    do
    {
        scanf("%d-%d", &a, &b);
        a--;
        product_sell[a] = b;
        a++;
    } while (a != 0);
    printf("Product Number\tQuantity sold\tprice\n");
    for (int i = 1; i != 6; i++)
    {
        c = product_sell[d] * price[d];
        total_peice += c;
        printf("%d\t\t", d);
        printf("%f\t%f\n", product_sell[d], c);
        d++;
    }
    printf("All Quantity sold: %f\n", total_peice);
    system("pause");
    return 0;
}