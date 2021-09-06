#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct customer
{
    char lastname[15];
    char firstname[15];
    unsigned int customerNumber;
    struct
    {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord, *customerPtr;


int main(void)
{
customerPtr = &customerRecord;
    strcpy(customerRecord.lastname, "Smith");
    strcpy(customerPtr->firstname, "andy");
    customerRecord.customerNumber = 201;
    strcpy(customerPtr->personal.phoneNumber, "09003838");
    strcpy(customerRecord.personal.address, "Pretty Way");
    strcpy(customerRecord.personal.city, "Bigcity");
    strcpy(customerRecord.personal.state, "SmallState");
    strcpy(customerRecord.personal.zipCode, "101");
puts(" ");
puts(" ");



    system("pause");
    return 0;
}