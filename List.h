#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node* next;
}Node;

Node*  InitList()
{
    Node* head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    return head;
}

int Empty(Node* head)
{
    if(head->next==NULL)
    {
        return -1;
    }
    else
        return 0;
}
//头插法
Node* creatlist_head(DataType a[],int n)
{
    Node* temp=NULL;
    Node* head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    for(int i;i<n;i++)
    {
        temp=(Node*)malloc(sizeof(Node));
        temp->data=a[i];
        temp->next=head->next;
        head->next=temp;
    }
    return head;
}

//尾插法
Node* creatlist_tail(DataType a[],int n)
{
    Node* temp=NULL;
    Node* move=NULL;
    Node* first=(Node*)malloc(sizeof(Node));
    move=first;
    for(int i;i<n;i++)
    {
        temp=(Node*)malloc(sizeof(Node));
        temp->data=a[i];
        move->next=temp;
        move=temp;
    }
    move->next=NULL;
    return first;
}



//遍历操作
void PrintList(Node* head)
{
    Node* p=head->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}

int Length(Node* head)
{
    Node* p=head->next;
    int count=0;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}

//按位查找
int Locate(Node* head,DataType x)
{
    Node* p=head->next;
    int count=1;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            return count;
        }
        p=p->next;
        count++;
    }
    return 0;
}
//按值查找
int Get(Node * first,int locate,DataType *ptr)
{
    Node* p=first->next;
    int count=1;
    while(p!=NULL&count<locate)
    {
        p=p->next;
        count++;
    }
    if(p==NULL)
    {
        printf("位置错误，查找失败\n");
        return 0;
    }
    else
    {
        *ptr=p->data;
        return 1;
    }
}

int Insert(Node* head,int locate,DataType x)
{
    Node* move=NULL;
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
        temp->next=move->next;
        move->next=temp;
        return 1;
    }
}


int Delete(Node* first,int locate,DataType* ptr)
{
    Node* move=first;
    Node* temp=NULL;
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
        temp=move->next;
        *ptr=temp->data;
        move->next=temp->next;
        free(temp);
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
