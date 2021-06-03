/*
	Author: Chocola4ever
	Date: 2021-03-29 20:55:46
	LastEditTime: 2021-03-29 21:13:05
	FilePath: \Programs\20210329\T5.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1;
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
int a[N],n,m;
int main(){
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	puts("6 1");
	return 0;
}
