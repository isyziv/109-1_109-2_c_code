#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum seasons
    {
        spring,
        summer,
        fall,
        winter
    };
    typedef enum seasons SEASON; //?D?????
    SEASON s;
    for (s = spring; s <= winter; s++)
    {
        switch (s)
        {
        case spring:
            printf("?K??\n");
            break;
        case summer:
            printf("?L??\n");
            break;
        case fall:
            printf("???\n");
            break;
        case winter:
            printf("?V??\n");
            break;
        default:
            break;
        }
        system("pause");
    }
}
/*////
?K??                //s=0;
??????N???~?? . . .
?L??                //s=1;
??????N???~?? . . .
???                //s=2;
??????N???~?? . . .
?V??                //s=3;
??????N???~?? . . . //(s <= winter)=1 ?????j??


*/
