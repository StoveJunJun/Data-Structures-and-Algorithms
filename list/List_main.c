#include "List.h"
int main()
{
    int array[5]={22,33,223,55,66};
    int ptr;
    //Node* head=creatlist_head(array,5);
    Node* head=creatlist_tail(array,5);
    // Node* head=InitList();
    // Insert(head,3,10);
    // Insert(head,4,11);
    // Insert(head,5,111);
    printf("当前链表的数据为\n");
    PrintList(head);

    int x=Get(head,5);
    printf("x:%d\n",x);

    // Delete(head,3,&ptr);
    // printf("当前链表的数据为\n");
    // PrintList(head);

    DestroyList(head);
}