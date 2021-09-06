#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int size, number, direction;
    int space;
    int h, i, j, k, m;
    int l = 1;
    int y, xx, yy, y__1;

    printf("Enter the side length of the diamond (between 3 and 10):");
    scanf("%d", &size);
    printf("Enter the connecting direction (0: horizontal, 1: vertical):");
    scanf("%d", &direction);
    printf("Enter the number of diamonds (between 2 and 6):");
    scanf("%d", &number);
    if (direction == 0)
    {
        yy = 1;
        y__1 = 1;
        xx = number;
    }
    if (direction == 1)
    {
        xx = 1;
        y__1 = number;
        yy = number;
    }
    if (size < 3 || size > 10 || number < 2 || number > 6 || direction < 0 || direction > 1) //error check
    {
        printf("input_error");
        system("pause");
        return 0;
    }
    space = size - 1;
    int space_1;
    space_1 = space;
    for (y = 0; y__1 != y; y++)
    {
        for (j = 0; j != xx; j++) //1st line
        {
            for (i = 0; i != space; i++) //print space
            {
                printf(" ");
            }
            printf("*");
            for (i = 0; i != space; i++) //print space
            {
                printf(" ");
            }
        }
        puts("");
        for (k = 0; k != space; k++)
        {
            space_1--;

            for (j = 0; j != xx; j++) // line
            {

                for (i = 0; i != space_1; i++) //print space
                {
                    printf(" ");
                }
                printf("*");
                for (m = 0; l != m; m++)
                {
                    printf("@");
                }

                printf("*");
                for (i = 0; i != space_1; i++) //print space
                {
                    printf(" ");
                }
            }
            puts("");
            l += 2;
        }
        printf("");
        l -= 4;
        for (k = space; k != 1; k--)
        {
            space_1++;

            for (j = 0; j != xx; j++) // line
            {

                for (i = space_1; i != 0; i--) //print space
                {
                    printf(" ");
                }
                printf("*");
                for (m = 0; l != m; m++)
                {
                    printf("@");
                }

                printf("*");
                for (i = space_1; i != 0; i--) //print space
                {
                    printf(" ");
                }
            }
            puts("");
            l -= 2;
        }
        for (j = 0; j != xx; j++) //last line
        {
            for (i = 0; i != space; i++) //print space
            {
                printf(" ");
            }
            printf("*");
            for (i = 0; i != space; i++) //print space
            {
                printf(" ");
            }
        }
        puts("");
        l = 1;
        space_1 = space;
    }
    system("pause");
    return 0;
}

