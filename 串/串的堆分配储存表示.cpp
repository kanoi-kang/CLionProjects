//
// Created by 22858 on 2023/12/21.
//
#include<bits/stdc++.h>
using namespace std;
#define Status int
//---------串的堆分配存储表示--------------------
typedef struct{
	char *ch;//按照需要分配内存
	int length;//串长度
}HString;
//---------基本操作的函数原型说明-----------------
Status StrAssign(HString &T,char *chars){
	int i;				//i为chars的长度
	char *c;
    for (i = 0, c = chars; *c; i++, c++);
    if (!i){
        T.ch = nullptr;
        T.length = 0;
    }
	else{
        T.ch = (char *)malloc(sizeof(char) * i);
        if (!T.ch)
            exit(_OVERFLOW);
        int tempi = 0;
        char *head = T.ch;
        do
        {
            tempi++;
            *T.ch = *chars;
            T.ch++;
            chars++;

        } while (tempi != i);
        T.ch = head;
        T.length = i;
        return 1;
	}
}

Status StrLength(HString S){
	return S.length;
}

Status StrCompare(HString S,HString T){
    for (int i = 0; i < S.length && i < T.length; i++)
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length;
}

Status ClearString(HString &S){
	if(S.ch){
        free(S.ch);
        S.ch = nullptr;
    }
    S.length = 0;
    return 1;
}

Status Concat(HString &T,HString S1,HString S2)
{
	if (T.ch){
		free(T.ch);
	}
    T.length = StrLength(S1) + StrLength(S2);
    T.ch = (char *)malloc(sizeof(char) * T.length);
    if (!T.ch){
        exit(_OVERFLOW);
    }
    char *head = T.ch;
    for (int i = 0; i < StrLength(S1); i++){
        *T.ch = *S1.ch;
        T.ch++;
        S1.ch++;
	}
    for (int i = StrLength(S1) - 1; i < T.length; i++){
        *T.ch = *S2.ch;
        T.ch++;
		S2.ch++;
	}
    T.ch = head;
    return 1;
}

Status SubString(HString &Sub,HString S,int pos,int len){
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
        return 0;
    if (Sub.ch)
        free(Sub.ch);
    if (!len){
        Sub.ch = nullptr;
        Sub.length = 0;
        return 1;
    }else{
        Sub.ch = (char *)malloc(sizeof(char) * len);
        Sub.length = len;
        char *head = Sub.ch;
        S.ch += pos - 1;
        for (int i=0;i<len;i++){
            *Sub.ch = *S.ch;
            Sub.ch++;
			S.ch++;
        }
        Sub.ch = head;
        return 1;
    }
}
//算法4.4
Status StrInsert(HString &S,int pos,HString T){
    int i;
    if (pos < 1 || pos > S.length + 1)
        return 0;
    if(T.length){
        if(!(S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char))))
            exit(_OVERFLOW);
        for (i = S.length - 1; i >= pos - 1;i--)
            S.ch[i + T.length] = S.ch[i];
        for (i = 0; i <= T.length - 1; i++)
            S.ch[i + pos - 1] = T.ch[i];
        S.length += T.length;
    }
    return 1;
}

void prinfStr(HString S)
{
	for (int i=0;i<S.length;i++)
	{
		printf("%c",*S.ch);
		S.ch++;
	}
	printf("\n");
}

