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
Linked_Stack top = NULL;          //���V���|���ݪ�����
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
    Linked_Stack new_add_node; //�s�[�J�`�I�����аt�m�s�`�I���O����
    new_add_node = (Linked_Stack)malloc(sizeof(Stack_Node));
    new_add_node->data = data; //�N�ǤJ���ȳ]���`�I�����e
    new_add_node->next = top;  //�N�s�`�I���V���|���I��
    top = new_add_node;        //�s�`�I�������|������
}
int pop()
{
    Linked_Stack ptr; //���V���|���ݪ�����
    int temp;
    if (isEmpty())
    {
        printf("���|����\n");
        return -1;
    }
    else
    {
        ptr = top;        //���V���|������
        temp = ptr->data; //���X���|���
        top = top->next;  //�N���|���ݪ����Ы��V�U�@�Ӹ`�I
        free(ptr);        //�N�`�I�e�Ϊ��O��������
        return temp;
    }
}

int main(int argc, char* argv[])
{
    
    int value;
    int i;
    printf("�Ш̧ǿ�J10�����:\n");
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
        printf("���|�u�X�����Ǭ�:%d\n", pop());
    }
    pop();
   
    system("pause");
    return 0;
}
 */