/*
	Author: Chocola4ever
	Date: 2021-04-21 08:42:02
	LastEditTime: 2021-04-21 10:25:18
	FilePath: \Programs\20210421\sequence\sequence.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+5,logN=22;
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
int st[N][logN],logn[N],a[N];
int n,ans=0,D;
void init(){
	logn[1]=0;
	logn[2]=1;
	for (int i=3;i<=N;++i)
		logn[i]=logn[i>>1]+1;
	for (int j=1;j<=logN;++j)
		for (int i=1;i+(1<<j)-1<=n;++i)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),D=read();
	for (int i=1;i<=n;++i)
		a[i]=st[i][0]=read();
	init();
	for (int l=1;l<=n;++l)
		for (int r=l;r<=n;++r){
			int s=logn[r-l+1];
			if ((a[l]^a[r]^min(st[l][s],st[r-(1<<s)+1][s]))==D) ++ans;
		}
	printf("%d\n",ans);
	return 0;
}