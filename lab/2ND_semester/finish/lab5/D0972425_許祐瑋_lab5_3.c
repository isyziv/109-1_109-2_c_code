//record ??

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
typedef struct employee Employee;
void out(Employee staff)
{
    puts(" ");
    printf("==============================================================================================================================================================================================================================================================================================================================");
    puts("\nthe highest paid employee is ");
    printf("ID :");
    printf("%d", staff.id);
    puts(" ");
    printf("lastName :");
    puts(staff.lastName);
    printf("firstName :");
    puts(staff.firstName);
    printf("gender :");
    puts(&staff.gender);
    printf("age :");
    printf("%d", staff.age);
    puts(" ");
    printf("salary :");
    printf("%f", staff.salary);
    puts(" ");
}
int math(int staff_number, Employee staff[staff_number])
{
    int value = 0;
    for (int i = 1; i != staff_number; i++)
    {
        if (staff[value].gender <= staff[i].salary)
        {
            if (staff[value].gender == staff[i].salary)
            {
                printf("alarm");
            }
            value = i;
        }
    }
    return value;
}
void in(int staff_number, Employee staff[staff_number])
{
    for (int i = 0; i != staff_number; i++)
    {
        printf("ID :");
        scanf("%d", &staff[i].id);
        printf("lastName :");
        fflush(stdin);
        scanf("%s", staff[i].lastName);
        printf("firstName :");
        fflush(stdin);
        scanf("%s", staff[i].firstName);
        fflush(stdout);
        printf("gender :");
        fflush(stdin);
        scanf("%s", &staff[i].gender);
        fflush(stdout);
        printf("age :");
        fflush(stdin);
        scanf("%d", &staff[i].age);
        fflush(stdout);
        printf("salary : ");
        fflush(stdin);
        scanf("%f", &staff[i].salary);
        puts(" ");
    }
}
int main(void)
{
    int staff_number;
    printf("array of employeerecords :");
    scanf("%d", &staff_number);
    Employee staff[100];
    in(staff_number, staff);
    puts(" ");
    int value = math(staff_number, staff);
    out(staff[value]);
    system("pause");
    return 0;
}