/*
	Author: Chocola4ever
	Date: 2021-04-23 14:41:38
	LastEditTime: 2021-04-23 15:52:25
	FilePath: \Programs\20210423\hanoi.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=100;
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
unsigned ll f[N+5][N+5];
inline void init(){
	memset(f,127,sizeof(f));
	f[1][1]=0;
	for (int i=2;i<=N;++i)
		f[1][i]=1;
	for (int i=1;i<=N;++i)
		for (int j=3;j<=N;++j)
			for (int k=1;k<i;++k)
				f[i][j]=min(f[i][j],(f[k][j]<<1)+f[i-k][j-1]);
}
int main(){
	freopen("hanoi.in","r",stdin);
	freopen("hanoi.out","w",stdout);
	init();
	// for (int i=1;i<=10;++i){
	// 	for (int j=3;j<=10;++j)
	// 		printf("%lld ",f[i][j]);
	// 	putchar('\n');
	// }
	for (int _=read();_--;){
		int n=read(),m=read();
		if (n>1&&m<3) puts("No Solution");
		else printf("%lld",f[n][m]),putchar('\n');
	}
	return 0;
}