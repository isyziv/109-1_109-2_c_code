#include <stdio.h>
#include <stdlib.h>
int main()
{

    FILE *cfptr;
    if ((cfptr = fopen("data.txt", "w")) == NULL)
    {
        printf("File could not be opened");
    }
    else
    {
        int accountnumber;
        char name[30];
        double balance;

        printf("enter accountnumber,name,balance\n");
        printf("enter EOF to end the program.\n");
        printf("enter accountnumber:");
        scanf("%d", &accountnumber);
        fflush(stdin);
        printf("enter name:");
        gets(name);
        fflush(stdin);
        printf("enter balance:");
        scanf("%lf", &balance);
        fflush(stdin);

        while (!feof(stdin))
        {
            fprintf(cfptr, "%-10d ", accountnumber);
            fprintf(cfptr, "%-13s ", name);
            fprintf(cfptr, "%.4f \n", balance);

            printf("enter account_number:  ");
            scanf("%d", &accountnumber);
            fflush(stdin);

            printf("enter name:  ");
            gets(name);
            fflush(stdin);

            printf("enter balance:  ");
            scanf("%lf", &balance);
            fflush(stdin);
        }
        fclose(cfptr);
    }

    return 0;
}