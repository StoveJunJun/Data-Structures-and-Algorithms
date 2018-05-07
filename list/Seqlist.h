#include<stdlib.h>
#include <stdio.h>
#define Maxsize 100

typedef int DataType;

typedef struct {
  DataType data[Maxsize];
  int length;
} Seqlist;

void Initlist(Seqlist *L) { L->length = 0; }

int creatlist(Seqlist *L, DataType a[], int n) {
  if (n > Maxsize) {
    printf("空间不够无法创建顺序表\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    L->data[i] = a[i];
  }
  L->length = n;
  return 1;
}

int Empty(Seqlist *L) {
  if (L->length == 0)
    return 1;
  else
    return 0;
}

int Length(Seqlist *L) { return L->length; }

void print_list(Seqlist *L) {
  for (int i = 0; i < L->length; i++)
    printf("%d\n", L->data[i]);
}

int Locate(Seqlist *L, DataType x) {
  for (int i = 0; i < L->length; i++)
    if (L->data[i] == x)
      return i + 1;
  return -1;
}
//按位查找
int Get(Seqlist *L, int locate, DataType *ptr) {
  if (locate < 1 || locate > L->length) {
    printf("查找位置非法\n");
    return 0;
  } else {
    *ptr = L->data[locate - 1];
      return *ptr;
  }
      return -1;
}

int Insert(Seqlist *L, int locate, DataType x) {
  if (L->length >= Maxsize)
  {
    printf("列表已满\n");
    return 0;
  }
  if (locate < 1 || locate > L->length + 1) {
    printf("位置错误\n");
    return 0;
  }
  for (int i = L->length; i >= locate; i--) {
    L->data[i] = L->data[i - 1];
  }
  L->data[locate - 1] = x;
  L->length++;
  return 1;
}

int Delete(Seqlist *L, int locate, DataType *ptr) {
  if (L->length == 0) {
    printf("下溢错误，删除失败\n");
    return 0;
  }
  if (locate < 1 || locate > L->length) {
    printf("位置错误删除失败\n");
    return 0;
  }
  *ptr = L->data[locate - 1]; //取出locate位置的元素
  for (int i = locate; i < L->length; i++) {
    L->data[i - 1] = L->data[i]; // locate 后面的元素统一往前移
  }
  L->length--;
  return 0;
}



