/*
	Author: Chocola4ever
	Date: 2021-04-16 08:37:10
	LastEditTime: 2021-04-16 09:16:08
	FilePath: \Programs\20210416\cook2.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=20005,M=20005;
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
int n,m,u[N],v[N],ans[M],cnt;
bool b[N];
int main(){
	int T=read();
	while (T--){
		cnt=0;
		memset(b,0,sizeof(b));
		n=read(),m=read();
		for (int i=1;i<=m;++i)
			u[i]=read(),v[i]=read();
		for (int i=m;i>=1;--i)
			if (!(b[u[i]]||b[v[i]])){
				ans[++cnt]=i-1;
				b[u[i]]=b[v[i]]=1;
			}
		for (int i=cnt;i>=1;--i)
			printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
