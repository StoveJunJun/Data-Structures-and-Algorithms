#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node* next;
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
/*
**********************************************************************
* name:creatlist_head
* brief:头插法建立一个链表
        每次将新申请的节点放在头结点的后面
        1、first.next->NULL;
        2、first.next->a[0];
            a[0].next->NULL;
        3、a[i].next->a[0];
        4、first.next->a[i]
**********************************************************************
*/
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

/*
**********************************************************************
* name:creatlist_tail
* brief:尾插法建立一个链表
        每次将新申请的节点放在原有结点的后面
        1、malloc first;
            tail=first;

        2、first.next->a[0];
            tail.next->=a[0];
            tail=a[0];
            tail->next=NULL;
        3、a[0].next->a[i];
        4、tail.next->=a[i];
            tail=a[i];
            tail.next=NULL;
**********************************************************************
*/
Node* creatlist_tail(DataType a[],int n)
{
    Node* temp=NULL;
    Node* tail=NULL;//尾结点初始化
    Node* first=(Node*)malloc(sizeof(Node));
    tail=first;
    for(int i;i<n;i++)
    {
        temp=(Node*)malloc(sizeof(Node));
        temp->data=a[i];
        tail->next=temp;//将temp插入到终端节点之后
        tail=temp;      
    }
    tail->next=NULL;//尾结点的指针域置空
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
        printf("\n");
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

/*
**********************************************************************
* name:Locate
* brief:返回具体某个结点的位置
**********************************************************************
*/
int Locate(Node* head,DataType x)
{
    Node* move=head->next;
    int count=1;
    while(move!=NULL)
    {
        if(move->data==x)
        {
            return count;
        }
        move=move->next;
        count++;
    }
    return 0;
}
/*
**********************************************************************
* name:Get
* brief:取出链表中某一个位置的值
**********************************************************************
*/
DataType Get(Node * first,int locate)
{
    Node* move=first->next;
    int count=1;
    while(move!=NULL&&count<locate)
    {
        move=move->next;
        count++;
    }
    
    if(move==NULL)
    {
        printf("位置错误，查找失败\n");
        return 0;
    }
    else
    {
        return move->data;
    }
}
/*
**********************************************************************
* name:Insert
* brief:在某个位置locate插入一个结点
    1、遍历指针move初始化并指向头节点
    2、查找第locate-1个结点并使move指向该结点
    3、查找不成功，则插入位置不合理，否则生成个新的结点。
        带头结点插入：
        temp.next=move.next;
        move.next->temp;
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
        temp->next=move->next;
        move->next=temp;
        return 1;
    }
}

/*
**********************************************************************
* name:Delete
* brief:删除某个位置Locate的元素
        1、move初始化，count初始化
        2、查找locate-1个结点并使move指向该结点
        3、若成功指向，
            3.1  通过temp将该结点信息保存下
            3.2  将move的后继结点从链表上摘下来，使move->next=move->next->next
            3.3  释放被删结点temp
**********************************************************************
*/
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
