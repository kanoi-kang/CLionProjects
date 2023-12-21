#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
/*严蔚敏版本的串代码实现，所有字
 符串数组的[0]位存的都是字符串长度*/
#include<iostream>
#include <cstring>
#define Status int
#define MAXSTRLEN 255
using namespace std;
typedef unsigned char SString[MAXSTRLEN+1];
/*字符串之用chars向T中赋值方法*/
Status StrAssign(SString &T,const char *chars){
    int len,uncut;
    int i;
    len=strlen(chars);
    if (len>MAXSTRLEN){
        //新数组的第一个位置放的是字符串chars的长度
        T[0]=MAXSTRLEN;
        uncut=0;
    }
    else{
        T[0]=len;
        uncut=1;
    }
    for (i = 1; i <T[0] ; ++i) {
        T[i]=chars[i-1];//从T[1]开始赋值，T[0]存放长度
    }
    return uncut;
    //返回字符串个数/状态，0表示字符串chars长度超过了MAXSTRLEN，1表示赋值成功
}
/*字符串复制方法*/
Status StrCopy(SString &T,SString S){
    if(S== nullptrptr)return 0;//表示复制失败
    for(int i=0;i<=S[0];i++)//S[0]代表字符串S的长度
        T[i]=S[i];
    return 1;//表示复制成功
}
/*字符串比较方法*/
Status StrCompare(SString S,SString T){
    if(S && T== nullptrptr)
        return 0;
    for(int i=1;i<=S[0]&&i<=T[0];i++){
        if(S[i]!=T[i])
            return S[i]-T[i];
    }
    return S[0]-T[0];
}
/*字符串判空方法*/
Status StrEmpty(SString S) {
	if (S == nullptrptr)
		return 0;
	if (S[0] == 0)
		return 1;
	else
		return 0;
}
/*返回字符串长度*/
Status StrLength(SString S) {
	//串S存在，返回S的元素个数
	if (S == nullptr)
		return 0;
	return S[0];
}
/*清空字符串*/
Status ClearString(SString &S) {
	//串S存在，将S清为空串
	if (S == nullptr)
		return 0;
	S[0] = 0;
	return 1;
}
/*链接字符串S1和S2，生成新的字符串T*/
Status Concat(SString &T, SString S1, SString S2) {
	int i, j;
	int uncut;
	if (S1 && S2 == nullptr)
		return 0;
	if (S1[0] + S2[0] <= MAXSTRLEN) {
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = S1[0] + 1, j = 1; i <= S1[0] + S2[0], j <= S2[0]; i++, j++)
			T[i] = S2[j];
		T[0] = S1[0] + S2[0];
		uncut = 1;
	}
	else if (S1[0] < MAXSTRLEN) {
		for(i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for(i = S1[0] + 1, j = 1; i <= MAXSTRLEN, j <= MAXSTRLEN - S1[0]; i++, j++)
			T[i] = S2[j];
		T[0] = MAXSTRLEN;
		uncut = 0;
	}
	else {
		for(i = 0; i <= MAXSTRLEN; i++)
			T[i] = S1[i];
		uncut = 0;
	}
	return uncut;
}
/*截取字符串*/
Status SubString(SString &Sub, SString S, int pos, int len) {
	if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
		return 0;
	int i, j;
	for(i = 1, j = pos; i <= len, j <= pos + len -1; i++, j++)
		Sub[i] = S[j];
	Sub[0] = len;
	return 1;
}
/*返回字符串中指定子字符串的位置*/
Status Index(SString S, SString T, int pos) {
	int n, m, i;
	if (pos > 0) {
		n = StrLength(S);
		m = StrLength(T);
		i = pos;
		SString sub;
		while(i <= n - m + 1) {
			SubString(sub, S, i, m);
			if (StrCompare(sub, T) != 0)
				i++;
			else
				return i;	//返回子串在主串中的位置
		}
	}
	return 0;				//S中不存在与T相等的子串
}



Status StrInsert(SString &S, int pos, SString T) {
	if ((S && T == nullptr) || (pos < 1) || (pos > S[0] + 1))
		return 0;
	int uncut;
	int i;
	if (S[0] + T[0] <= MAXSTRLEN) {
		for(i = S[0]; i >= pos; i--)
			S[i + T[0]] = S[i];
		for(i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] += T[0];
		uncut = 1;
	}
	else {
		for(i = MAXSTRLEN; i >= pos; i--)
			S[i] = S[i - T[0]];
		for(i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = MAXSTRLEN;
		uncut = 0;
	}
}

Status StrDelete(SString &S, int pos, int len) {
	if ((S == nullptr) || (pos < 1) || (pos > S[0] - len + 1) || (len < 0))
		return 0;
	int i;
	for(i = pos; i <= pos + len; i++)
		S[i] = S[i + len];
	S[0] -= len;
	return 1;
}
/*替换某段字符串的位置*/
Status Replace(SString &S, SString T, SString V) {
	int i = 1;
	if (StrEmpty(T))
		return 0;
	while(i) {
		i = Index(S, T, i);
		if (i) {
			StrDelete(S, i, T[0]);
			StrInsert(S, i, V);
			i += V[0];
		}
	}
	return 1;
}
Status DestroyString (SString &S) {
	return 0;
}
