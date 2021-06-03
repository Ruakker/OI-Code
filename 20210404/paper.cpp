/*
	Author: Chocola4ever
	Date: 2021-04-04 09:58:11
	LastEditTime: 2021-04-04 10:16:54
	FilePath: \Programs\20210404\paper.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=3005;
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
int n,m,x=1,y=1;
char a[N][N];
void solvex(int l,int r){
	for (int i=1;i<=n-1;++i)
		for (int j=i+1;j<=n;j+=2){
			bool canadd=1;
			for (int k=i;k<=(i+j)>>1;++k){
				for (int t=1;t<=m;++t){
					if (a[k]!=a[j-(k-i)])
				}
				if (!canadd) break;
			}
		}
}
void solvey(){
	for (int i=1;i<=m-1;++i)
		for (int j=i+1;j<=m;++j){
			bool noans=0;
			for (int k=1;k<=n;++k)
				if (a[k][i]!=a[k][j]){
					noans=1;
					break;
				}
			if (noans) continue;
			++y;
		}
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;++i)
		scanf("%s",a[i]+1);
	solvex();
	solvey();
	printf("%d",x*y);
	return 0;
}