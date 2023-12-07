#include <iostream>
#include "malloc.h"
using namespace std;
typedef struct LNode {//定义单链表类型
    int data;
    struct LNode *next;
} *LinkList;

/*初始化单链表*/
void InitList(LinkList &L){
    L=(LNode *) malloc(sizeof (LinkList));
    L->next=nullptr;
}
/*头插法建立链表*/
LinkList HeadInsert(LinkList &L){
    InitList(L);
    int x;
    cin>>x;
    while(x!=9999){//输入9999表示结束
        LNode *s;
        s = (LNode *) malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        cin>>x;
    }
    return L;
}
/*尾插法建立链表*/
LinkList TailInsert(LinkList &L){
    InitList(L);
    LNode *s,*r=L;
    int x;
    cin>>x;
    while(x!=9999){
        s=(LNode *) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        cin>>x;
    }
    r->next=nullptr;
    return L;
}
//遍历操作
void PrintList(LinkList L){
    LNode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
/*求单链表长度*/
int Length(LinkList L){
    LNode *p=L->next;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
/*按值查找，找其位置*/
LNode *LocateElem(LinkList L,int x){
    LNode *p=L->next;
    while(p&&p->data!=x){
        p=p->next;
    }
    return p;
}
/*按位查找*/
LNode *GetElem(LinkList L,int i){
    int j=1;
    LNode *p=L->next;
    if(i==0)return L;
    if(i<1)return nullptr;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
/*插入操作*/
void Insert(LinkList &L,int i,int x){
    LNode *p= GetElem(L,i-1);
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
}
/*删除操作*/
void Delete(LinkList &L,int i){
    if(i<1||i> Length(L))
    {
        cout<<"delete failed: index is wrong."<<endl;
        return;
    }
    LNode *p= GetElem(L,i-1);
    LNode *q=p->next;
    p->next=q->next;
    free(q);
}
/*判空操作*/
bool Empty(LinkList L){
    if (L->next==nullptr)
    {
        cout<<"L is null"<<endl;
        return true;
    }else{
        cout<<"L is not null"<<endl;
        return false;
    }
}
int main() {
    //初始化，尾插法建立单链表
    LinkList L = TailInsert(L);
    //插入：在第二个位置插入结点，数据域为888，并遍历单链表
    Insert(L,2,888);
    cout<<"在第二个位置插入888： ";
    PrintList(L);
    //删除：删除第四个结点
    Delete(L,4);
    cout<<"删除第四个结点后：";
    PrintList(L);
    //按位查找：查找第三个结点，并输出其数据域的值
    LNode *p = GetElem(L,3);
    cout<<"第三个结点的值为："<<p->data<<endl;
    //按值查找：查找数据域为2的结点的指针
    LNode *q = LocateElem(L,2);
    cout<<"数据为2的结点的下一个结点的值为："<<q->next->data<<endl;
    //输出单链表的长度
    cout<<"单链表的长度："<<Length(L)<<endl;
    return 0;
}
