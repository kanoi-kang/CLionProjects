/*两栈共享空间结构*/
#include <iostream>
#define MAXSIZE 50
#define OK 1
#define ERROR 0
using namespace std;
typedef int ElemType,Status;
typedef struct{
    ElemType data[MAXSIZE];
    int top0;//栈0的顶指针
    int top1;//栈1的栈顶指针
}SqDoubleStack;
void InitStack(SqDoubleStack *S){
    S->top0=-1;
    S->top1=MAXSIZE;
}
/*共享栈进栈*/
Status Push(SqDoubleStack *S,ElemType e,int stackNumber){
    if(S->top0+1==S->top1)//栈满
        return ERROR;
    if(stackNumber==0)//栈0有元素进栈
        S->data[++S->top0]=e;
    else if (stackNumber==1)
        S->data[++S->top1]=e;
    else {
        cout<<"压入失败,您所输入的栈号不存在!"<<endl;
        return false;
    }
    return OK;
}
/*共享栈出栈*/
Status Pop(SqDoubleStack *S,ElemType *e,int stackNumber){
    if(stackNumber==0){
        if(S->top0==-1)
            return ERROR;
        *e=S->data[S->top0--];
    }
    else if(stackNumber==1){
        if(S->top1==MAXSIZE){
            return ERROR;
        }
        *e=S->data[S->top1++];
    }
    return OK;
}
int main() {
    SqDoubleStack S;
    int stackNumber;
    InitStack(&S);
    do{
        int e,num,i=1;
        cout<<"请输入要压入栈的第"<<i++<<"个元素:";
        cin>>e;
        cout<<"请输入要压入哪个栈:";cin>>num;
        Push(&S,e,num);
    }while(S.top0+1!=S.top1);
    //这里的循环只有栈满才能结束
    int target,num;
    cout<<"请输入要弹出哪个栈的栈顶元素:";cin>>num;
    Pop(&S,&target,num);
    return 0;
}
