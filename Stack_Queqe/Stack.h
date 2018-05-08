#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<stdlib.h>
#define Stacksize 100
typedef int Datatype;
typedef struct 
{
    Datatype data[Stacksize];
    int top;
}SeqStack;



void InitStack(SeqStack* stack)
{
    stack->top=-1;
}
int Push(SeqStack* stack,Datatype x)
{
    if(stack->top==Stacksize-1)
    {
        printf("上溢错误，插入失败\n");
        return 0;
    }
    stack->data[++stack->top]=x;
    return 1;
}

int Pop(SeqStack* stack,Datatype* ptr)
{
    if(stack->top==-1)
    {
        printf("下溢错误，删除失败\n");
        return 0;
    }
    *ptr=stack->data[stack->top--];
    return 1;   
}

int GetTop(SeqStack* stack,Datatype* ptr)
{
    if(stack->top==-1)
    {
        printf("下溢错误，取栈顶失败\n");
        return 0;
    }
    *ptr=stack->data[stack->top];
    return 1;
}

int Empty(SeqStack* stack)
{
    if(stack->top==-1)
        return 1;
    else
        return 0;
}
#endif // STACK_H


