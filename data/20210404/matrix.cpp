/*
	Author: Chocola4ever
	Date: 2021-04-04 08:08:07
	LastEditTime: 2021-04-04 12:00:57
	FilePath: \Programs\20210404\matrix.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=60;
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
int n,m;
int a[N][N],a2[N][N];
int x[5],y[5];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	n=read(),m=read();
	if (n>4){
		puts("__________________________________________________");
		puts("|                                                |");
		puts("| You F**king B**ch,I Don't Know HOW TO DO IT!!! |");
		puts("|________________________________________________|");
		return 0;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			a[i][j]=read();
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j)
			x[i]|=a[i][j],y[i]|=a[j][i];
	}
	int cntx=0,cnty=0;
	for (int i=1;i<=n;++i)
		if (x[i])
			for (int j=1;j<=n;++j)
				if (a[i][j]==0) ++cntx;
	for (int i=1;i<=n;++i)
		if (y[i])
			for (int j=1;j<=n;++j)
				if (a[j][i]==0) ++cnty;
	if (cntx<cnty){
		for (int i=1;i<=n;++i)
			if (x[i])
				for (int j=1;j<=n;++j)
					a[i][j]=1;
	}else{
		for (int i=1;i<=n;++i)
			if (y[i])
				for (int j=1;j<=n;++j)
					a[j][i]=1;
	}
/*	bool b=0;
	for (int i=2;i<=n;++i){
		for (int j=2;j<=n;++j){
			if (a[j][i]-a[j][i-1]!=a[j-1][i]-a[j-1][i-1]){
				b=1;
				break;
			}
		}
		if (b) break;
	}
	if (b){
		for (int i=1;i<=n;++i)
			if (y[i]){
				for (int j=1;j<=n;++j)
					a[j][i]=1;
			}
	}*/
	int ans=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			if (a[i][j]) ++ans;
	printf("%d\n",ans);
	if (m){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j)
				printf("%d ",a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
