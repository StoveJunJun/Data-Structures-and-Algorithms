#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef int Datatype;
typedef struct
{
    Datatype    data;
    struct Node* next;
    
}Node;
void InitStack(Node* top)
{
    top=NULL;
}

void DestroyStack(Node* top)
{
    Node* p=top;
    while(top!=NULL)
    {
        top=top->next;
        free(p);
        p=top;
    }
}

void Push(Node* top,Datatype x)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

int Pop(Node* top,Datatype* ptr)
{
    Node* p=top;
    if (top==NULL)
    {
        printf("下溢错误，删除失败\n");
        return 0;
    }
    *ptr=top->data;
    top=top->next;
    free(p);
    return 1;
}

int Empty(Node* top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
int GetTop(Node* top,Datatype *ptr)
{
    if(top==NULL)
    {
        printf("下溢错误，删除失败\n");
        return 0;       
    }
    *ptr=top->data;
    return 1;
}


#endif // LINKED_STACK_H
