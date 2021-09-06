#define _CRT_SECURE_NO_WARNINGS
#include "link_list.h"
//#include "link_setup.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //*initialization
    link top,tmp;
    tmp = generate_link();
    top=generate_link();
    //
    top->data = 1;
    //*add a node before top
    top = insert(top);
    //
    top->data = 2;
    puts("blyat");

    system("pause");
    return 0;
}
/*//extern void link_setup();
Linked_Stack top = NULL;          //指向堆疊頂端的指標
int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int data)
{
    Linked_Stack new_add_node; //新加入節點的指標配置新節點的記憶體
    new_add_node = (Linked_Stack)malloc(sizeof(Stack_Node));
    new_add_node->data = data; //將傳入的值設為節點的內容
    new_add_node->next = top;  //將新節點指向堆疊的點端
    top = new_add_node;        //新節點成為堆疊的頂端
}
int pop()
{
    Linked_Stack ptr; //指向堆疊頂端的指標
    int temp;
    if (isEmpty())
    {
        printf("堆疊為空\n");
        return -1;
    }
    else
    {
        ptr = top;        //指向堆疊的頂端
        temp = ptr->data; //取出堆疊資料
        top = top->next;  //將堆疊頂端的指標指向下一個節點
        free(ptr);        //將節點占用的記憶體釋放
        return temp;
    }
}

int main(int argc, char* argv[])
{
    
    int value;
    int i;
    printf("請依序輸入10筆資料:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &value);
        push(value);
    }
    printf("====================\n");
    int c = sub(top);
    printf("%d",c);
    /*while (!isEmpty())
    {
        printf("堆疊彈出的順序為:%d\n", pop());
    }
    pop();
   
    system("pause");
    return 0;
}
 */