/*
	Author: Chocola4ever
	Date: 2021-04-08 14:01:40
	LastEditTime: 2021-04-08 15:29:16
	FilePath: \Programs\20210408\love.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+5;
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
int n,posans[N],negans[N],xa[N];
ll xb[N];
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	n=read();
	xa[0]=xb[0]=0;
	for (int i=1;i<=n;++i)
		xa[i]=xa[i-1]+read();
	for (int i=1;i<=n;++i)
		xb[i]=xb[i-1]+read();
	for (int i=1;i<=n;++i)
		for (int j=i;j<=n;++j){
			if (xb[j]-xb[i-1]>0){
				if (xa[j]-xa[i-1]>=0)
					++posans[xa[j]-xa[i-1]];else
					++negans[xa[i-1]-xa[j]];
			}else
			if (xb[j]-xb[i-1]<0){
				if (xa[j]-xa[i-1]>0)
					++negans[xa[j]-xa[i-1]];else
					++posans[xa[i-1]-xa[j]];
			}/*
	for (int i=n;i>=1;--i)
		printf("%d ",negans[i]);
	for (int i=0;i<=n;++i)
		printf("%d ",posans[i]);
	putchar('\n');*/
		}
	for (int i=n;i>=1;--i)
		printf("%d ",negans[i]);
	for (int i=0;i<=n;++i)
		printf("%d ",posans[i]);
	putchar('\n');
	return 0;
}