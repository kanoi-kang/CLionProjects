#include <iostream>
#include <cmath>
#include<malloc.h>
using namespace std;
#define OK 1
#define ERROR 0
typedef int ElemType,Status;
/*定义节点结构*/
typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
/*定义链式结构*/
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
/*初始化链队*/
Status InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(QueuePtr) malloc(sizeof(QNode));
    if(!Q.front){
        exit(_OVERFLOW);
    }
    Q.front->next= nullptr;
    return OK;
}
/*销毁链队*/
Status DestoryQueue(LinkQueue &Q){
    while(Q.front){
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }
    return OK;
}
/*置空*/
Status ClearQueue(LinkQueue &Q){
    QueuePtr p,q;
    Q.rear=Q.front;
    p=Q.front->next;
    Q.front->next=nullptr;
    while(p){
        q=p;
        p=p->next;
        free(q);
    }
    return OK;
}
/*判空*/
Status QueueEmpty(LinkQueue Q){
    if(Q.front==Q.rear)return OK;
    else return ERROR;
}
/*链队长度*/
int QueueLength(LinkQueue Q){
    int i=0;
    QueuePtr p;
    p=Q.front;
    while(Q.rear!=p){
        i++;
        p=p->next;
    }
    return i;
}
/*读取队头元素*/
Status GetHead(LinkQueue Q,ElemType &e){
    QueuePtr p;
    if(Q.front == Q.rear)
        return ERROR;
    p=Q.front->next;
    e=p->data;
    return OK;
}
/*进队*/
Status EnQueue(LinkQueue &Q,ElemType e){
    QueuePtr p;
    p = (QueuePtr) malloc(sizeof(QNode));
    if(!p)
        exit(_OVERFLOW);
    p->data=e;
    p->next=nullptr;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}
/*出队*/
Status  DeQueue(LinkQueue &Q,ElemType &e){
    QueuePtr p;
    if(Q.front==Q.rear){
        return ERROR;
    }
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return OK;
}
/*设计模式*/
void visit(ElemType a){
    cout<<a<<" ";
}
/*从队头到队尾输出链队中的每个元素*/
Status QueueTraverse(LinkQueue &Q,void(*visit)(ElemType)){
    QueuePtr p;
    p=Q.front->next;
    while(p){
        visit(p->data);
        p=p->next;
    }
    cout<<endl;
    return OK;
}
int main() {
    LinkQueue Q;
    InitQueue(Q);
    int e,i=2;
    cout<<"请输入第1个进队元素:";cin>>e;
    while(e!=9999){
        EnQueue(Q,e);
        cout<<"此时链队长度为:"<<QueueLength(Q)<<endl;
        cout<<"请输入第"<<i++<<"个进队元素";
        cin>>e;
    }
    if(!QueueEmpty(Q)) {
        DeQueue(Q, e);
        cout<<"出队的元素是:"<<e<<endl;
        GetHead(Q,e);
        cout<<"此时链队的队头元素为:"<<e<<endl;
    }else cout<<"此时链队为空!";
    if (QueueEmpty(Q))cout << "链队空了哦。" << endl;
    else {
        cout<<"以下是链队里的所有数据(从左到右是从队头到队尾的元素):"<<endl;
        QueueTraverse(Q,visit);
        //void(*visit)(ElemType)对应的参数调用形式为直接输入函数名(这里是visit)。
    }

    ClearQueue(Q);

    return 0;
}


