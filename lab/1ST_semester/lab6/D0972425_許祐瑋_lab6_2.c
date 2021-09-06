#include <stdio.h>
#include <stdlib.h>
int check_c(int x, int y)
{
    int check;
    if (x > 12 || x < 1)
    {
        check = 1;
    }
    if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
        if (x > 31)
        {
            check = 1;
        }
    if (x == 4 || x == 4 || x == 9 || x == 11)
    {
        if (x > 30)
        {
            check = 1;
        }
    }
    if (x == 2)
    {
        if (x > 29)
        {
            check = 1;
        }
    }
    if (x == 0 || y == 0)
    {
        check = 1;
    }
    return check;
}
int main(void)
{

    int m2 = 0;
    int m1 = 0;
    int d2 = 0;
    int d1 = 0;
    int x = 0;
    int y = 0; //mm/dd = x/y = ab/cd
    int a = 0, i = 0;
    int d_ten = 0;
    unsigned char a_return[3];
    unsigned char month[3], monthb[3], daya[3], dayb[3];
    month[0] = month[1] = monthb[0] = monthb[1] = daya[0] = daya[1] = dayb[0] = dayb[1] = month[3] = monthb[3] = daya[3] = dayb[3] = a_return[3] = '\0';
re_type:
    printf("input date ");
    scanf("%d/%d", &x, &y);
    int check;
    check = check_c(x, y);
    if (check)
    {
        int alarm;
        puts("date seems wrong");
        puts("if you still continued please type 0");
        puts("or type 1 to retype date or any number to exit");
        scanf("%d", &alarm);
        switch (alarm)
        {
        case 0:

            break;
        case 1:
            goto re_type;
            break;
        default:
            return 0;
            break;
        }
    }

    if (x >= 10)
    {
        //month = 'a';
        m1 = x - 10;
        m2 = 1;
    }
    else
    {
        m1 = x;
    }
    if (y >= 10)
    {
        d2 = y / 10;
        d1 = y - (d2 * 10);
        d_ten = 1;
    }
    else
    {
        d1 = y;
    }
    for (i = 1; i <= 4; i++)
    {

        if (i == 1)
        {
            a = m2;
        }
        if (i == 2)
        {
            a = m1;
        }
        if (i == 3)
        {
            a = d2;
        }
        if (i == 4)
        {
            a = d1;
        }
        switch (a)
        {
        case 1:
            a_return[0] = '\xA4';
            a_return[1] = '\x40';
            break;
        case 2:
            a_return[0] = '\xA4';
            a_return[1] = '\x47';
            break;
        case 3:
            a_return[0] = '\xA4';
            a_return[1] = '\x54';
            break;
        case 4:
            a_return[0] = '\xA5';
            a_return[1] = '\x7C';
            break;
        case 5:
            a_return[0] = '\xA5';
            a_return[1] = '\xAD';
            break;
        case 6:
            a_return[0] = '\xA4';
            a_return[1] = '\xBB';
            break;
        case 7:
            a_return[0] = '\xA4';
            a_return[1] = '\x43';
            break;
        case 8:
            a_return[0] = '\xA4';
            a_return[1] = '\x4B';
            break;
        case 9:
            a_return[0] = '\xA4';
            a_return[1] = '\x45';
            break;
        default:
            a_return[0] = '\0';
            a_return[1] = '\0';
            break;
        }
        if (i == 1)
        {
            month[0] = a_return[0];
            month[1] = a_return[1];
        }
        if (i == 2)
        {
            monthb[0] = a_return[0];
            monthb[1] = a_return[1];
        }
        if (i == 3)
        {
            daya[0] = a_return[0];
            daya[1] = a_return[1];
        }
        if (i == 4)
        {
            dayb[0] = a_return[0];
            dayb[1] = a_return[1];
        }
    }
    if (m2 == 1)
    {
        printf("¢Ì");
    }
    printf("%s", monthb);
    printf("¤ë");
    printf("%s", daya);
    if (d_ten == 1)
    {
        printf("¢Ì");
    }
    printf("%s", dayb);
    printf("¤é");
    puts("");
    system("pause");
    return 0;
}
