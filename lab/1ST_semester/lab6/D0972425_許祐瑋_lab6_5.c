#include <stdio.h>
#include <stdlib.h>
int size, direction, number;
int at_number, o_space, i_space;
int error;
int x, y;
int up_size;
int midle_plus;
void scan_data()
{
    printf("Enter the side length of the diamond (between5 and 10): ");
    scanf("%d", &size);
    printf("Enter the connecting direction (0: horizontal, 1: vertical): ");
    scanf("%d", &direction);
    printf("Enter the number of diamonds (between 3 and 5): ");
    scanf("%d", &number);
}
void math_p()
{
    at_number = (size * 2) + 1;
    o_space = size - 1;
    x = size - 1;
    up_size = size - 2;
    midle_plus = (size * 2) - 3;
}
void input_check()
{
    if (size <= 4 || size >= 11 || direction > 1 || direction < 0 || number < 2 || number > 6)
    {
        printf("input error\n");
        error = 1;
    }
}
void math_size()
{
    if (direction == 0)
    {
        x = number;
        y = 1;
    }
    if (direction == 1)
    {
        y = number;
        x = 1;
    }
}
void print_at()
{
    for (int xx = 0; x != xx; xx++)
    {
        for (int i = 0; i != at_number; i++)
        {
            printf("@");
        }
        printf(" ");
    }
    printf("\n");
}
void print_first()
{
    int xx = 0;
    for (; x != xx; xx++)
    {
        printf("@");
        for (int i = 0; i != o_space; i++)
        {
            printf(" ");
        }
        printf("*");
        for (int i = 0; i != o_space; i++)
        {
            printf(" ");
        }
        printf("@ ");
    }
    printf("\n");
}
void print_up()
{
    for (int j = 0; up_size != j; j++)
    {
        o_space--;

        for (int xx = 0; x != xx; xx++)
        {
            printf("@");
            for (int i = 0; i != o_space; i++)
            {
                printf(" ");
            }
            printf("*");
            for (int i = 0; i != i_space; i++)
            {
                printf(" ");
            }
            printf("+");
            for (int i = 0; i != i_space; i++)
            {
                printf(" ");
            }
            printf("*");
            for (int i = 0; i != o_space; i++)
            {
                printf(" ");
            }
            printf("@");
            printf(" ");
        }
        printf("\n");

        i_space++;
    }
}
void print_middle()
{
    for (int xx = 0; x != xx; xx++)
    {
        printf("@*");
        for (int i = 0; i != midle_plus; i++)
        {
            printf("+");
        }
        printf("*@");
        printf(" ");
    }
    printf("\n");
}
void print_down()
{
    for (int j = 0; up_size != j; j++)
    {

        i_space--;
        for (int xx = 0; x != xx; xx++)
        {
            printf("@");
            for (int i = 0; i != o_space; i++)
            {
                printf(" ");
            }
            printf("*");
            for (int i = 0; i != i_space; i++)
            {
                printf(" ");
            }
            printf("+");
            for (int i = 0; i != i_space; i++)
            {
                printf(" ");
            }
            printf("*");
            for (int i = 0; i != o_space; i++)
            {
                printf(" ");
            }
            printf("@");
            printf(" ");
        }
        printf("\n");
        o_space++;
    }
}
int main(void)
{

    scan_data();
    math_p();
    input_check();
    if (error == 1)
    {
        system("pause");
        return 0;
    }
    math_size();
    for (int yy = 0; y != yy; yy++)
    {
        print_at();
        print_first();
        print_up();
        print_middle();
        print_down();
        print_first();
        print_at();
    }
    system("pause");
    return 0;
}
