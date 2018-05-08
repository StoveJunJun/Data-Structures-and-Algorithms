/*
**********************************************************************
* name:josephroll
* author:Stove
* brief:设n个人围成一个环，n个人的编号分别为1，2，.... n 从第一个人开始报数，
报到m时停止报数，报m的人出环，再重新报数，直到所有人出环为止。求出环次序
    解决方案：
        设置一个count和工作指针p；
        当累加到m时删除该结点p；循环单链表不带头结点，为了便于删除操作，设两个
        工作指针pre和p，pre指向结点p的前驱结点
        为了使计数器从1开始计数，采用尾指针指示的循环单链表。将pre初始化为指向
        终端结点，p初始化为指向开始结点。
* date:2018/5/8
* log:
**********************************************************************
*/

/*
**********************************************************************
* name:Joseph(rear,m)
* brief:1.初始化： pre=rear;
                    p=rear->next;
                    count=1;
        2.重复如下操作,直到只剩下一个节点
            2.1 if(count<m)
                2.1.1 pre和p后移
                2.1.2 count++
            2.2 else
                2.2.1 输出p->data;
                2.2.2 删除p;
                2.2.3 p指向pre的后继节点，count=1;
            3.输出p->data,delete p;

**********************************************************************
*/

#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* creat(int n)
{
    Node* rear=NULL;//定义尾指针并初始化
    Node* temp;
    int i;
    rear=(Node*)malloc(sizeof(Node));//建立长度为1的循环单链表
    rear->data=1;
    rear->next=rear;
    for(i=2;i<=n;i++)//插入数据域为1~n的结点
    {
        temp=(Node*)malloc(sizeof(Node));
        temp->data=i;
        temp->next=rear->next;//新结点插入rear结点的后面
        rear->next=temp;
        rear=temp;//rear指向当前尾结点
    }
    return rear;
}

void Joseph(Node* rear,int m)
{
    Node* pre=rear;
    Node* p=rear->next;
    int count=1;
    printf("出环顺序为\n");
    while(p->next!=p)
    {
        if(count<m)
        {
            pre=p;
            p=p->next;
            count++;
        }
        else
        {
            printf("%-3d\n",p->data);
            pre->next=p->next;
            free(p);
            p=pre->next;
            count=1;
        }
    }
    printf("%-3d\n",p->data);
    free(p);
}
Node* creat(int n);
void Joseph(Node* rear,int m);
int main(int argc,const char* argv[])
{
    Node* rear=creat(18);
    Joseph(rear,4);
    return 0;
}
