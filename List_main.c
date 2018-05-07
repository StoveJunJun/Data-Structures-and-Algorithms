#include "List.h"
int main()
{
    // int array[5]={22,33,223,55,66};
    // int i,x;
    // Node* first=creatlist_head(array,5);
    Node* head=InitList();
    Insert(head,1,10);
    Insert(head,2,11);
    Insert(head,3,111);
    printf("当前链表的数据为\n");
    PrintList(head);
}