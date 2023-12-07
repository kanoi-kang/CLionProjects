#include <iostream>
using namespace std;
#include "malloc.h"
#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int ElemType,Status;
/*定义顺序队列结构*/
/*#define MAXSIZE 50	//定义队列中元素的最大个数
typedef struct{
	ElemType data[MAXSIZE];	//存放队列元素
	int front,rear;
}SqQueue;
*/
/*定义循环队列结构*/
typedef struct {
    ElemType data[MAXSIZE];
    int front;//头指针
    int rear;//尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;
/*初始化一个空队列*/
Status InitQueue(SqQueue *Q){
    Q->front=0;
    Q->rear=0;
    return OK;
}
/*队列判空*/
bool isEmpty(SqQueue *Q){
    if(Q->front==Q->rear){
        return true;
    }else{
        return false;
    }
}
/*求队列长度*/
int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MAXSIZE) %MAXSIZE;
}
/*进队,若队列未满，则插入元素e为Q新的队尾元素*/
Status EnQueue(SqQueue *Q,ElemType e){
    if((Q->rear+1)%MAXSIZE == Q->front){
        cout<<"插入失败,队已经满了！"<<endl;
        return ERROR;
    }
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}
/*出队,若队列非空,删除队列中的队头元素*/
Status DeQueue(SqQueue *Q,ElemType *e){
    if(isEmpty(Q)){
        cout<<"队列已空,无元素可删！"<<endl;
        return ERROR;
    }
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
};
int main() {
    SqQueue Q;
    InitQueue(&Q);
    int x,i=2;
    cout<<"请输入第1个进队的元素:";cin>>x;
    while(x!=9999){
        EnQueue(&Q,x);
        cout<<"请输入第"<<i++<<"个要进队的元素:";
        cin>>x;
    }
    int e;
    DeQueue(&Q,&e);
    cout<<"出队的是:"<<e<<endl;
    return 0;
}
