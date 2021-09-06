#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct customer
{
    int customerNumber;
    char lastName[15];
    char firstName[15];
    char phoneNumber[11];
    double balance;
};
void out(struct customer data)
{
    puts(" ");
    printf("==============================================================================================================================================================================================================================================================================================================================");
    puts(" ");
    printf("customerNumber :");
    printf("%d", data.customerNumber);
    puts(" ");
    printf("lastName :");
    puts(data.lastName);
    //printf("\n");
    printf("firstName :");
    puts(data.firstName);
    printf("phoneNumbe :");
    puts(data.phoneNumber);
    printf("balance :");
    printf("%lf", data.balance);
    puts(" ");
}
int main(void)
{
    struct customer data;
    printf("customerNumber :");
    scanf("%d", &data.customerNumber);
    printf("lastName :");
    fflush(stdin);
    scanf("%s", data.lastName);
    printf("firstName :");
    fflush(stdin);
    scanf("%s", data.firstName);
    printf("phoneNumbe :");
    fflush(stdin);
    scanf("%s", data.phoneNumber);
    printf("balance :");
    scanf("%lf", &data.balance);
    out(data);
    system("pause");
    return 0;
}
