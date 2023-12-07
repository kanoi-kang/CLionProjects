/*线性表的创销增删查改*/
//静态数组没办法销毁，想要销毁需要换动态数组。
#include <iostream>
#define InitSize 10//链表初始长度
#include "windows.h"
#include <malloc.h>
using namespace std;
/*定义链表结构*/
typedef struct SqList {
    int *data;
    int MaxSize;
    int length;//计数器，用于记录顺序表的长度
};
/*顺序表初始化*/
void InitList(SqList &L,int e) {
    L.MaxSize=InitSize;
    L.data=(int *) malloc(InitSize*sizeof(int));
    L.length = 0;//顺序表初始长度为0
    int i=0;
    cout<<"请依次输入元素:"<<endl;
    while(cin>>L.data[i]){
        i++;
        L.length++;
        if(i>=e)break;
    }
}
/*销毁线性表*/
bool DestroySeqList(SqList &L){
	if(!L.data){
		cout<<"线性表不存在"<<endl;
		return false;
	}
	free(L.data);
	L.data = nullptr;
    L.length=0;
	cout<<"\n线性表已销毁\n"<<endl;
	return true;
}
/*增加顺序表的长度*/
void IncreaseSize(SqList &L,int len){
    int *p=L.data;
    L.data=(int *) malloc((L.MaxSize+len)* sizeof (int));
     for (int i = 0; i < L.length; i++)
    {
        /* code */
        L.data[i] = p[i];  //将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len; //顺序表最大长度增加len
    free(p);  //释放原来的内存空间
}
/*插入线性表*/
bool ListInsert(SqList& L, int i, int e) {
    //判断i的范围是否有效
    if (i<1 || i>L.length + 1) {
        cout<<"您输入的值超出了范围，请重新输入！"<<endl;
        return false;
    }
    //判断当前存储空间是否已满，不能插入
    if (L.length >= L.MaxSize)
    {
        cout<<"当前顺序表存储空间已满！"<<endl;
        return false;
    }
    //将第i个元素及以后的元素后移
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    //在位置i处放入e
    L.data[i - 1] = e;
    L.length++;//长度++
    cout << "插入操作已完成!" << "插入的是第" << i << "个元素" << e << endl;
    return true;
}
/*删除线性表*/
bool ListDelete(SqList& L, int i, int& e) {
    if(L.length<=0){
        cout<<"表中已无可删除的元素。"<<endl;
        return false;
    }
    /*判断i的范围是否有效*/
    if (i<1 || i>L.length + 1)return false;
    e = L.data[i - 1];
    /*将第i个元素及以后的元素前移*/
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    cout << "删除操作已完成" << "删除的是第" << i << "个元素" << e << endl;
    return true;
}
/*按位查找*/
void ListSearchBySite(SqList L, int i) {
    /*判断是否处于范围以内*/
    if (i<1 || i>L.length + 1) {
        cout << "抱歉！您输入的范围不在有效范围以内。\n请输入" << "1~" << L.length << "范围以内的值" << endl;
        return ;
    }
    cout << "您所查找的第" << i << "位的值为:"<<L.data[i-1]<<endl;
}
/*按值查找*/
void ListSearchByValue(SqList L,int i){
    //查找函数代码，可以用更加高效的查找算法，这里用的是效率最低的遍历
    for(int j=0;j<L.length;j++){
        if(L.data[j]==i) {
            cout<<"找到了！"<<i<<"的位置为:"<<j+1<<endl;
            return;
        }
    }
    cout<<"抱歉！没有查到······"<<endl;
}
/*修改线性表中的值*/
void Modify(SqList &L,int i,int num){
    L.data[i]=num;
}
/*打印输出*/
void printList(SqList L) {
    cout<<"-------------------------------"<<endl;
    cout << "长度length=" << L.length << endl;
    cout << "数据为：" << endl;
    for (int i = 0; i < L.length; ++i) {
        cout << "data[" << i << "]=" << L.data[i] << endl;
    }
    cout<<"-------------------------------"<<endl;
}
/*操作菜单*/
void Menu(){
    cout<<"****************Menu*****************"<<endl;
    cout<<"   0--------------创建顺序表"<<endl;
    cout<<"   1--------------增加顺序表"<<endl;
    cout<<"   2--------------插入元素"<<endl;
    cout<<"   3--------------删除元素"<<endl;
    cout<<"   4--------------按位查找元素"<<endl;
    cout<<"   5--------------按值查找元素"<<endl;
    cout<<"   6--------------修改元素"<<endl;
    cout<<"   7--------------销毁顺序表"<<endl;
    cout<<"   8--------------菜单"<<endl;
    cout<<"   9--------------查看当前表的内容"<<endl;
    cout<<"****************Menu*****************"<<endl;
}
int main() {
    SqList L{};
    /*//设置控制台输出字体颜色为绿色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);*/
    int op=0;
    Menu();
    while(op!=-1) {
        cout << "请输入操作方法:";
        cin >> op;
        switch (op) {
            case 0:{
                int i;
                cout<<"请输入您要输入的元素个数:";cin >> i;
                InitList(L, i);
                break;
            }
            case 1:{
                int len;
                cout<<"请输入您要增加的长度:";cin>>len;
                IncreaseSize(L,len);
                break;
            }
            case 2: {
                int i, e;
                cout << "请输入您要插入的位置:";cin >> i;
                cout << "请输入您要插入的元素:";cin >> e;
                ListInsert(L, i, e);
                cout << "这是插入之后的线性表:" << endl;
                printList(L);break;
            }
            case 3: {
                int e, i;
                cout << "请输出您要删除的位置:";cin >> i;
                ListDelete(L, i, e);
                cout << "这是删除之后的线性表";
                printList(L);break;
            }
            case 4: {
                int i;
                cout << "请输入您要查找的数的位数:";cin >> i;
                ListSearchBySite(L, i);
                break;
            }
            case 5: {
                int q;
                cout << "请输入您要查找的数:";cin >> q;
                ListSearchByValue(L, q);
                break;
            }
            case 6:
            {
                int i,num;
                cout<<"请输入您要修改的位序:";cin>>i;
                cout<<"请输入您要修改成的数值:";cin>>num;
                Modify(L,i,num);break;
            }
            case 7:{
                DestroySeqList(L);break;
            }
            case 8:{
                Menu();break;
            }
            case 9:{
                printList(L);break;
            }
        }
    }
    return 0;
}