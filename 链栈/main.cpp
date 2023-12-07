#include <iostream>
#include<cstdio>
using namespace std;
#include<malloc.h>
#define OK 1;
#define ERROR 0;
typedef int ElemType,Status;
/*栈的链式储存结构*/
/*构造节点*/
typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode;
/*构造链栈*/
typedef struct LinkStack{
    StackNode *top;//top为指针类型，指向栈StackNode
    int count;//count变量可有可无，用来当作链栈长度的计数器，可用于判满操作
}LinkStack;
/*初始化链栈*/
void InitStack(LinkStack *S){
    S->top= nullptr;
    cout<<"链栈初始化完成！"<<endl;
}
/*将链栈置空*/
Status SetEmpty(LinkStack *s){
    StackNode *p=s->top;
    while(p){
        s->top=p->next;
        free(p);
        p=s->top;
    }
    cout<<"链栈已置空！";
    return OK;
}
/*进栈*/
Status Push(LinkStack *s,ElemType e){
    /*if(s->count==MAXSIZE){
        cut<<"栈满了，请重新输入元素！";
        return ERROR;
    }*///链栈不存在栈满的情况,不需要判满操作
    StackNode *p;
    p= (StackNode *)malloc(sizeof(StackNode));
    p->data=e;
    p->next=s->top;
    s->top=p;
    return OK;
};

/*出栈*/
Status Pop(LinkStack *s,ElemType *e){//第二个参数用来显示出栈的元素
    StackNode *p=s->top;
    if(s->top==nullptr){
        cout<<"栈空，不能进行出栈操作！";
        return ERROR;
    }
    s->top=p->next;//让栈顶指针指向前一个元素
    *e=p->data;
    free(p);
    return OK;
}
/*读取栈顶元素*/
Status GetTop(LinkStack *s,ElemType *e){
    if(s->top== nullptr){
        cout<<"栈已空，栈顶无元素可读！";
        return ERROR;
    }
    *e=s->top->data;
    return OK;
}
/*打印栈中所有元素*/
Status PrintStack(LinkStack *s){
    StackNode *p;
    p=s->top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return OK;
}

int main() {
    //以下为测试代码段
    LinkStack s;
	InitStack(&s);
	int n, e;
	printf("请输入链栈长度:");
    cin>>n;
	puts("请输入要录入的数据:");
	while(n--)
	{
		int x;
        cin>>x;
        Push(&s, x);
	}
	PrintStack(&s);
	GetTop(&s, &e);
	printf("栈顶元素为：%d\n",e);
	puts("8入栈后：");
	Push(&s,8);
	PrintStack(&s);
	Pop(&s, &e);
	printf("出栈元素是：%d\n", e);
	puts("出栈后栈内元素为：");
	PrintStack(&s);
    SetEmpty(&s);
    return 0;
}
