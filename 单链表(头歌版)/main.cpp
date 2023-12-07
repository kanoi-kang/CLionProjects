#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

     // 请在此添加你的代码
    /********** Begin *********/
Node *CreatList(void){
    int val,i,n;
    Node *phead,*p,*q;//这里需要三个指针，phead作为头指针需要作为函数的参数传出去
    //q指针作为交换时的左指针，p指针作为交换时的右指针
    phead=(Node *)malloc(sizeof(struct node));
    q=phead;//首地址赋给指针q
    q->next=NULL;//单链表初始化，指向空指针
    scanf("%d",&n);
    //尾插法建立单链表，好处在于可以顺序读入和输出
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        p=(Node *)malloc(sizeof(struct node));//为新的结构体类型申请空间
        //以下三行代码为交换地址
        p->data=val;//存值
        q->next=p;//交换地址，使得左边的指针指向新建立的结构体
        p->next=NULL;//新建立的结构体指向空指针
        //完成值的传递，继续向后重复以上操作创建新的结构体类型
        q=p;//关键在于这一步，把结构体类型的p的值传给同类型的q,完成值的传递
    }
    return phead;//根据题目所需返回头指针的地址
}
void ShowList(Node *phead){
    Node *p;
//带头节点（phead）的单链表，头节点(phead)不能动
//所以需要新建一个局部结构体指针来作为遍历链表的媒介
    p=phead->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
Node *ReverseList(Node *phead)
{
    Node *p,*q;
    p=phead->next;
    phead->next=NULL;
//保证头节点地址仍旧知道的情况下(即头节点地址已经赋给了局部结构体指针),先拆掉头节点
    while(p)
    {
        /*向后挪动一个位置*/
        q=p;
        p=p->next;
        /*头插*/
        q->next=phead->next;
        phead->next=q;
    }
    return phead;
}
    /**********  End  **********/
int main(void)
{
    Node *phead;
    phead = CreatList();
    printf("链表逆置前的数据:\n");
    ShowList(phead);
    phead = ReverseList(phead);
    printf("链表逆置后的数据:\n");
    ShowList(phead);
    return 0;
}