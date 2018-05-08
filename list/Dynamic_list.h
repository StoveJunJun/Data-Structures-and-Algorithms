#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

const int Initsize=100;
const int IncreSize=10;
typedef int DataType;
typedef struct{
    DataType* data;
    int maxsize;
    int length;
}Seqlist;

void Init(Seqlist* L)
{
    L->data=(DataType*)malloc(Initsize*sizeof(DataType));
    L->maxsize=Initsize;
    L->length=0;
}

void create(Seqlist* L,DataType *array,int n)
{
    L->data=(DataType*)malloc(Initsize*sizeof(DataType));
    L->maxsize=Initsize;
    while(n<L->maxsize)
    {
        L->maxsize=L->maxsize+IncreSize;
        L->data=(DataType*)realloc(L->data,L->maxsize*sizeof(DataType));
    }
    for(int i;i<n;i++)
    {
        L->data[i]=array[i];
    }
    L->length=n;
}


void destroy(Seqlist* L)
{
    free(L->data);
}


int Insert(Seqlist* L,int locate,DataType x)
{
    if(i<1||i>L->length+1)
    {
        printf("位置")；
        return 0;
    }
    if(L->length>=L->maxsize)
    {
        L->maxsize=L->maxsize+IncreSize;
        L->data=(DataType*)realloc(L->data,L->maxsize*sizeof(DataType));
    }
    for(int i;i<L->length;i>=locate;i--)
    {
        L->data[i]=L->data[i-1];
    }
    L->data[i-1]=x;
    L->length++
    return 1;
}