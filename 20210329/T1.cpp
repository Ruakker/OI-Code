/*
	Author: Chocola4ever
	Date: 2021-03-29 18:13:29
	LastEditTime: 2021-03-29 21:12:23
	FilePath: \Programs\20210329\T1.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1005;
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
struct{
	int val,lastid;
}dp[N];
bool remain[N];
int n,maxa,a[N];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	n=read(),maxa=read();
	memset(remain,1,sizeof(remain));
	for (int i=1;i<=n;++i)
		a[i]=read();
	for (int i=1;i<=n;++i)
		if (a[i]<=maxa)
			if (a[i]>dp[1].val){
				dp[1].val=a[i];
				remain[dp[1].lastid]=1;
				remain[i]=0;
				dp[1].lastid=i;
			}
	for (int i=2;i<=n;++i){
		for (int j=1;j<=n;++j)
			if (remain[j]&&a[j]-a[dp[i-1].lastid]<=maxa&&a[j]-a[dp[i-1].lastid]>0)
				if (dp[i-2].val+a[j]>dp[i].val){
					dp[i].val=dp[i-2].val+a[j];
					remain[dp[i].lastid]=1;
					remain[j]=0;
					dp[i].lastid=j;
				}
		if (dp[i].val==0){
			if (i&1)
				printf("%d",dp[i-2].val-dp[i-1].val);
			else
				printf("%d",dp[i-1].val-dp[i-2].val);
			return 0;
		}
	}
	printf("%d",dp[n-1].val-dp[n].val);
	return 0;
}