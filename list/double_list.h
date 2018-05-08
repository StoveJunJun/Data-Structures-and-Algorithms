#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node* next;//指向后一结点
    struct Node* pre;//指向前一结点
}Node;

/*
**********************************************************************
* name:InitList
* brief:初始化一个只有头节点的链表
**********************************************************************
*/
Node*  InitList()
{
    Node* head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->pre=NULL;
    return head;
}
/*
**********************************************************************
* name:Empty
* brief:判断链表是否为空
**********************************************************************
*/
int Empty(Node* head)
{
    if(head->next==NULL)
    {
        return -1;
    }
    else
        return 0;
}

void PrintList(Node* head)
{
    Node* p=head->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
        printf("\n");
    }
}

/*
**********************************************************************
* name:Insert
* brief:在某个位置locate后插入一个结点
        locate位置上的结点为p
        1 temp->pre=p;
        2 temp->next=p->next;
        3 p->next->pre=temp;
        4 p->next=temp;
**********************************************************************
*/
int Insert(Node* head,int locate,DataType x)
{
    Node* move=head;
    int count=0;
    while(move!=NULL&&count<locate-1)
    {
        move=move->next;
        count++;
    }
    if(move==NULL)
    {
        printf("位置错误，插入失败\n");
        return 0;
    }
    else
    {
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->pre=move;
        temp->next=move->next;
        move->next->pre=temp;
        move->next=temp;
        return 1;
    }
}


/*
**********************************************************************
* name:Delete
* brief:删除某个位置Locate的元素
        move指向locate
        1 move-> pre->next=move->next;
        2 move->next->pre=move->pre;
**********************************************************************
*/
int Delete(Node* first,int locate,DataType* ptr)
{
    Node* move=first;
    int count=0;
    DataType x;
    while(move !=NULL && count<locate-1)
    {
        move=move->next;
        count++;
    }
    if(move==NULL||move->next==NULL)
    {
        printf("位置错误，删除失败\n");
        return 0;
    }
    else
    {
        // temp=move->next;
        // *ptr=temp->data;
        // move->next=temp->next;
        // free(temp);

        move->pre->next=move->next;
        move->next->pre=move->pre;
        free(move);
        return 1;        
    }
}

void DestroyList(Node* first)
{
    Node* move=first;
    while(first !=NULL)
    {
        first=first->next;
        free(move);
        move=first;
    }
}


