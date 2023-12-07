#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef struct DoubleLinkedList
{
    int data;
    DoubleLinkedList *prior,*next;

}DNode,*DLinkList;
/*初始化*/
bool InitDLinkList(DLinkList &L){
    L=(DNode *)malloc(sizeof (DNode));
    if(L== nullptr)
        return false;
    L->prior= nullptr;
    L->next=nullptr;
    return true;
}
/*判断双链表是否为空*/
bool isEmpty(DLinkList L){
    return (L->next == nullptr);
}
/*插入数据*/
bool InsertNode(DLinkList &L,int e){
    DNode *s;
    DNode *temp=L;
    while (temp->next!= nullptr){
        temp=temp->next;
    }
    s=(DNode *) malloc(sizeof (DNode));
    s->data=e;
    s->next=temp->next;
    if(temp->next!=nullptr){
        temp->next->prior=s;
    }
    s->prior=temp;
    temp->next=s;
    cout<<"插入成功"<<endl;
    return true;
}
/*向后遍历数据*/
void printNodetoNext(DLinkList L){
    cout<<"向后遍历"<<endl;
    DNode *p=L->next;
    while(p != nullptr){
        cout<<p->data<<endl;
        p=p->next;
    }
}
/*向前遍历*/
void printNodetoPrior(DLinkList L){
    cout<<"向前遍历"<<endl;
    DNode *p=L;
    while(p->prior!=nullptr){
        cout<<p->data<<endl;
        p=p->prior;
    }
}
/*删除指定位置*/
bool DeleteNode(DLinkList &L,int i){
    DNode *p=L;
    int j=0;
    while(j<i-1){
        p=p->next;
        j++;
    }
    DNode *q=p->next;
    p->next=q->next;
    if(q->next!=nullptr){
        q->next->prior=p;
    }
    free(q);
    cout<<"删除成功"<<endl;
    return true;
}
int main() {
    DLinkList L;
    InitDLinkList(L);
    cout << isEmpty(L) << endl;
    //插入数据
    InsertNode(L, 4);
    InsertNode(L, 2);
    InsertNode(L, 5);
    InsertNode(L, 8);
    //
    printNodetoNext(L);
    //
    DeleteNode(L, 2);
    printNodetoNext(L);
    return 0;
}
