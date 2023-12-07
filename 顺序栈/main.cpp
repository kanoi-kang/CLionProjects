#include <iostream>
using namespace std;
#define MAXSIZE 10 //定义最大空间
#define ElemType int //可视情况修改元素的数据类型
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct {
    ElemType data[MAXSIZE];
    int top;//栈顶指针
}SqStack;

/*栈的初始化*/
void InitStack(SqStack *S){
    S->top=-1;//初始化栈顶指针
}
/*栈判空*/
bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
}
/*进栈，插入元素e为新的栈顶元素*/
Status Push(SqStack *S,ElemType e){
    //栈满
    if(S->top==MAXSIZE-1){
        return ERROR;
    }
    S->top++;//栈顶指针加1
    S->data[S->top]=e;//将新插入元素赋值给栈顶空间
    return OK;
}
/*出栈*/
Status Pop(SqStack *S,ElemType *e){
    //若栈不空，则删除S的栈顶元素，用e返回值，并返回OK；否则返回ERROR
    if(S->top==-1)
        return ERROR;
    *e=S->data[S->top];
    S->top--;
    return OK;
}
/*读栈顶元素*/
Status GetTop(SqStack S,ElemType *e){
    if(S.top==-1)
        return ERROR;
    *e=S.data[S.top];
    return OK;
}
int main() {
    SqStack S;
    InitStack( &S);
    int e;
    cin>>e;
    Push(&S,e);
    GetTop(S,&e);
    Pop(&S,&e);
    if(StackEmpty(S))cout<<"栈空了，你满意了？"<<endl;
    else cout<<"栈没空哦！"<<endl;
    return 0;
}
