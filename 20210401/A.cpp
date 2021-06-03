/*
	Author: Chocola4ever
	Date: 2021-04-01 08:06:02
	LastEditTime: 2021-04-01 09:12:18
	FilePath: \Programs\20210401\A.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=70005;
inline ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-')
			w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
int main(){
	int n,t=read();
	for (int _=1;_<=t;++_){
		char s1[N],s2[N];
		n=read();
		int nn=1<<n;
		scanf("%s",&s1);
		for (int i=0;i<=nn-1;++i){
			int k=i,a=0;
			for (int j=n;k>0;k>>=1,--j)
				a|=((k&1)<<(j-1));
			putchar(s1[a]);
		}
		putchar('\n');
	}
	return 0;
}
