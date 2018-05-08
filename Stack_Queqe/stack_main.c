//#include "Stack.h"
#include "linked_stack.h"

int main(int argc, char const *argv[])
{
    Datatype x;
    // SeqStack stack;
    // InitStack(&stack);
    node* stack=NULL;
    InitStack(stack);
    printf("对15和10入栈\n");
    Push(&stack,15);
    Push(&stack,10);
    //Push(&stack,111);
    if (GetTop(&stack,&x)==1)
    {
        printf("当前栈顶元素为%d\n",x);

    }
    Pop(&stack,&x);
    printf("出栈元素为%d\n",x);
    Pop(&stack,&x);
    if (Empty(&stack)==1)
    {
        printf("栈为空\n");
    }
    return 0;
}
