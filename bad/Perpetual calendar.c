#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int leapyear(int v)
{
    int b;
    if (v % 4 != 0)
    {
        b = 0;
    }
    else
    {
        b = 1;
        if (v % 100 == 0)
        {
            b = 0;
            if (v % 400 == 0)
            {
                b = 1;
            }
        }
    }
    return b;
}
int monthday(int year, int month)
{
    int firstday = 0;
    month--;
    switch (month)
    {

    case 11:
        firstday += 2;
    case 10:
        firstday += 3;
    case 9:
        firstday += 2;
    case 8:
        firstday += 3;
    case 7:
        firstday += 3;
    case 6:
        firstday += 2;
    case 5:
        firstday += 3;
    case 4:
        firstday += 2;
    case 3:
        firstday += 3;
    case 2:
        if (leapyear(year) == 1)
        {
            firstday += 1;
        }
        else
        {
            firstday += 0;
        }
    case 1:
        firstday += 3;
        break;
    }
    firstday %= 7;
    return firstday;
}
int yearday(int year)
{
    int i = 0;
    int yeartmp;
    for (yeartmp = 1; year != yeartmp; yeartmp++)
    {
        if (leapyear(yeartmp) == 1)
        {
            i++;
        }
    }
    i += yeartmp;
    i %= 7;
    return i;
}
int day(int month, int year)
{
    int day = 0;
    switch (month)
    {
    case 12:
        day = 31;
        break;
    case 11:
        day = 30;
        break;
    case 10:
        day = 31;
        break;
    case 9:
        day = 30;
        break;
    case 8:
        day = 31;
        break;
    case 7:
        day = 31;
        break;
    case 6:
        day = 30;
        break;
    case 5:
        day = 31;
        break;
    case 4:
        day = 30;
        break;
    case 3:
        day = 31;
        break;
    case 2:
        if (leapyear(year) == 1)
        {
            day = 29;
        }
        else
        {
            day = 28;
        }
        break;
    case 1:
        day = 31;
        break;
    }
    return day;
}
void out_header()
{
    printf(" SUN MON TUE WED TUE FRI SAT\n");
}
int method0(int j)
{
    int date = 1;
    for (int i = 0; i != 7; i++)
    {
        if (j != 0)
        {
            printf("    ");
            j--;
        }
        else
        {
            printf("%4d", date);
            date++;
        }
    }
    puts(" ");
    return date;
}
void method1(int date, int end_date)
{
    for (int i = 0; 1; i++)
    {
        if (i == 7)
        {
            i = 0;
            puts(" ");
        }
        printf("%4d", date);

        if (date == end_date)
        {
            break;
        }
        date++;
    }
}
int main(void)
{
res:
    int month, year, dayday = 0;
    printf("input year/month :");
    scanf("%d/%d", &year, &month);
    dayday += monthday(year, month);
    dayday += yearday(year);
    int end_date = day(month, year);
    //start
    out_header();
    int first_day = dayday % 7;
    int date = method0(first_day);
    method1(date, end_date);
    puts(" ");
    puts(" ");
    goto res;
    system("pause");
    return 0;
}

/*
l4.(*)請設計一個萬年曆,可以輸入任意年份(year)及月份(month),印出該月份月曆. 
以2001年3月份為例,格式如下: 
SU MO TU WE TH FR SA 
1 2 3 
4 5 6 7 8 9 10 
11 12 13 14 15 16 17 
18 19 20 21 22 23 24 
25 26 27 28 29 30 31 
(註:1.一年中,每月日數如下表,潤年二月份29日,平年28日
月份1 2 3 4 5 6 7 8 9 10 11 12 
日數31 28 31 30 31 30 31 31 30 31 30 31 
2.潤年之判斷為4年一潤,逢100年不潤,逢400年又潤
3.故西元1年1月1日為星期一,而一年有52個星期零1天, 
故西元2年1月1日為星期二,以此類推.) 

*/