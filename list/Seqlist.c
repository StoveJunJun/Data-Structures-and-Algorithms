#include "Seqlist.h"

int main()
{
    int r[5]={31,23,22,33,88};
    int i;
    int x;
    Seqlist L;
    creatlist(&L,r,5);
    printf("数据为\n");
    print_list(&L);

    printf("数据的位置为%d\n", Locate(&L,1));

    printf("该位置的数据为%d\n",Get(&L,4,&x));


    printf("删除后\n");
    Delete(&L,4,&x);
    print_list(&L);


    Insert(&L,5,9);
    printf("插入后\n");

    printf("线性表的长度为%d\n",Length(&L));
    print_list(&L);
}