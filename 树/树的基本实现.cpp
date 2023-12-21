#pragma clang diagnostic push
#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-branch-clone"
#pragma ide diagnostic ignored "misc-no-recursion"
#include <bits/stdc++.h>
using namespace std;
#define TElemType char
#define Status int
//------------二叉树的二叉链表存储表示-------------
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//------------基本操作的函数原型说明---------------
Status InitBiTree(BiTree &T);
Status DestroyBiTree(BiTree &T);
Status CreateBiTree(BiTree &T);
void ClearBiTree(BiTree &T);
Status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
Status Value(BiTree T, TElemType e);
Status Assign(BiTree &T, TElemType e, TElemType value);
Status Parent(BiTree T, TElemType e);
Status LeftChild(BiTree T, TElemType e);
Status RightChild(BiTree T, TElemType e);
Status LeftSibling(BiTree T, TElemType e);
Status RightSibling(BiTree T, TElemType e);
Status InsertChild(BiTree T, BiTree p, int LR, BiTree c);
Status DeleteChild(BiTree T, BiTree p, int LR);
//-----------------具体实现-----------------------
/*初始化一个二叉树*/
Status InitBiTree(BiTree &T){
    T=nullptr;
    return 1;
}
/*清空并销毁二叉树*/
Status DestroyBiTree(BiTree &T){
    if(T->lchild)
        DestroyBiTree(T->lchild);
    if(T->rchild)
        DestroyBiTree(T->rchild);
    free(T);
    T=nullptr;
    return 1;
}
/*创建二叉树并申请空间*/
Status CreateBiTree(BiTree &T){
    TElemType ch;
    scanf("%c",&ch);
    if (ch==' ')
        T= nullptr;
    else{
        T=(BiTree) malloc(sizeof( BiTNode) );
        if(!T)
            exit(_OVERFLOW);
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 1;
}
/*清空二叉树中的数据但不销毁空间*/
void ClearBiTree(BiTree &T){
    if(T){
      if(T->lchild)
          ClearBiTree(T->lchild);
      if(T->rchild)
          ClearBiTree(T->rchild);
      free(T);
      T=nullptr;
    }
}
/*树的判空操作*/
Status BiTreeEmpty(BiTree T){
   if(T)
       return 0;
   else
       return 1;
}
/*计算树的深度*/
int BiTreeDepth(BiTree T){
    int i,j;
    if(!T)
        return 0;
    if(T->lchild)
        i= BiTreeDepth(T->lchild);
    else
        i=1;
    if(T->rchild)
        j= BiTreeDepth(T->rchild);
    else
        j=1;
    return i>j?i:j;
}
/*递归遍历二叉树并查找是否存在元素e*/
Status Value(BiTree T,TElemType e){
    if(T->data==e)
        return 1;//每次递归（遍历二叉树的所有节点）都会判断是否是目标值
    else{
        int i=0,j=0;
        //根左右的先序遍历方式
        if(T->lchild)
            i= Value(T->lchild,e);
        if(T->rchild)
            j= Value(T->rchild,e);
        if(i||j)
            return 1;
        else
            return 0;
    }
    //return 0;不可到达代码，上面的else中return 0的作用和这里的return 0重复了
}
/*替换二叉树中的指定元素,和Value方法几乎一致*/
Status Assign(BiTree &T,TElemType e,TElemType value){
    if(T->data==e){
        T->data=value;//因为要做值的修改操作所以需要&引用方法
        return 1;//每次递归（遍历二叉树的所有节点）都会判断是否是目标值
    }
    else{
        int i=0,j=0;
        //根左右的先序遍历方式
        if(T->lchild)
            i= Assign(T->lchild,e,value);
        if(T->rchild)
            j= Assign(T->rchild,e,value);
        if(i||j)
            return 1;
        else
            return 0;
    }
    //return 0;不可到达代码，上面的else中return 0的作用和这里的return 0重复了
}
/*递归遍历二叉树并找目标值的双亲节点*/
Status Parent(BiTree T,TElemType e){
    if(T->lchild&&T->lchild->data==e){
        printf("双亲节点为:%c\n",T->data);
        return 1;
    }
    else if(T->rchild&&T->rchild->data==e) {
        printf("双亲节点为:%c\n", T->data);
        return 1;
    }//以上为找到了的操作，以下为找不到的情况下递归遍历到下一个节点继续找
    else{
        if(T->lchild)
            Parent(T->lchild,e);
        if(T->rchild)
            Parent(T->rchild,e);
    }
    return 0;//全都没有则返回0表示没找到
}
/*查找某个元素的左孩子*/
Status LeftChild(BiTree T,TElemType e){
    if(T->data==e&&T->data){
        printf("左孩子节点为:%c\n",T->lchild->data);
        return 1;
    }
    else{
        if(T->lchild)
            LeftChild(T->lchild,e);
        if(T->rchild)
            LeftChild(T->rchild,e);
    }
    return 0;
}
/*查找某个元素的右孩子*/
Status RightChild(BiTree T,TElemType e){
    if(T->data==e&&T->data){
        printf("右孩子节点为:%c\n",T->rchild->data);
        return 1;
    }
    else{
        if(T->lchild)
            LeftChild(T->lchild,e);
        if(T->rchild)
            LeftChild(T->rchild,e);
    }
    return 0;
}
/*查找某个元素的左兄弟节点*/
Status LeftSibling(BiTree T,TElemType e){
	if(T->lchild&&T->rchild->data==e){
		printf("左兄弟节点为：%c\n",T->lchild->data);
		return 1;
	}
	else{
		if(T->lchild){
			LeftSibling(T->lchild,e);
		}
		if(T->rchild){
			LeftSibling(T->rchild,e);
		}
	}
	return 0;
}
/*查找某个元素的右兄弟节点*/
Status RightSibling(BiTree T,TElemType e){
	if(T->rchild&&T->lchild->data==e){
		printf("右兄弟节点为：%c\n",T->rchild->data);
		return 1;
	}
	else{
		if(T->lchild){
			RightSibling(T->lchild,e);
		}
		if(T->rchild){
			RightSibling(T->rchild,e);
		}
	}
	return 0;
}
/*插入左右子树形成新的二叉树*/
Status InsertChild(BiTree p,int LR,BiTree c){
	if(LR==0){//c的右子树为空，使p的左子树成为c的右子树，并使增加了右子树的c成为p的左子树
		c->rchild=p->lchild;
		p->lchild=c;
	}
	else{//c的右子树为空，使p的右子树成为c的右子树，并使增加了右子树的c成为p的右子树
		c->rchild=p->rchild;
		p->rchild=c;
	}
	return 1;
}
/*删除左右子树*/
Status DeleteChild(BiTree p,int LR){
	if(LR==0){//删除p的左子树
		DestroyBiTree(p->lchild);
	}
	else{//删除p的右子树
		DestroyBiTree(p->rchild);
	}
	return 1;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


