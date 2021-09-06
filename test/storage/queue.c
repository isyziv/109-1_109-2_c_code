#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct sta
{
    int data;
    struct sta *next;
};
typedef struct sta s;
typedef s *st;
st stack = NULL; //top
int choose_mod()
{
    int mod;
    printf("1: push\n2: pop\n");
    scanf("%d", &mod);
    return mod;
}
int in()
{
    int data;
    printf("data = ");
    scanf("%d", &data);
    return data;
}
void push()
{
    st new;
    new = (st)malloc(sizeof(s));
    new->data = in();
    new->next = stack;
    stack = new;
}
void pull()
{
    st a1, a2;
    a1 = stack;
    a2 = stack->next;
    stack = a2;
    free(a1);
}
int main(void)
{
    for (int mod; 1;)
    {
        mod = choose_mod();
        if (mod == 1)
        {
            push();
        }
        if (mod == 2)
        {
            pull();
        }
    }
    system("pause");
    return 0;
}