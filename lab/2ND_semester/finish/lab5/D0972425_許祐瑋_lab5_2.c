#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct employee
{
    int id;
    char lastName[15];
    char firstName[15];
    char gender;
    int age;
    float salary;
};
void math(struct employee data)
{
    puts(" ");
    printf("==============================================================================================================================================================================================================================================================================================================================");
    puts(" ");
    printf("ID :");
    printf("%d", data.id);
    puts(" ");
    printf("lastName :");
    puts(data.lastName);
    printf("firstName :");
    puts(data.firstName);
    printf("gender :");
    puts(&data.gender);
    printf("age :");
    printf("%d", data.age);
    puts(" ");
    printf("salary :");
    printf("%f", data.salary);
    puts(" ");
}
int main(void)
{
    struct employee data;
    printf("ID : ");
    scanf("%d", &data.id);
    printf("lastName :");
    fflush(stdin);
    scanf("%s", data.lastName);
    printf("firstName :");
    fflush(stdin);
    scanf("%s", data.firstName);
    fflush(stdout);
    printf("gender : ");
    fflush(stdin);
    scanf("%s", &data.gender);
    fflush(stdout);
    printf("age : ");
    fflush(stdin);
    scanf("%d", &data.age);
    fflush(stdout);
    printf("salary : ");
    fflush(stdin);
    scanf("%f", &data.salary);
    puts(" ");
    var out = data();
    printf(out);
    math(data);
    system("pause");
    return 0;
}