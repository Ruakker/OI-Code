/*
	Author: Chocola4ever
	Date: 2021-03-30 07:53:16
	LastEditTime: 2021-03-30 12:08:39
	FilePath: \Programs\20210330\arc.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=15005,M=5005;
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
int n,c[N];
ll ans=0;
bool segt[M<<2],isused[N];
int lztag[M<<2];//if it is used:1
vector<int> loc[M];
inline void pushdown(int l,int r,int k){
	int mid=(l+r)>>1;
	segt[k<<1]=lztag[k];
	segt[(k<<1)|1]=lztag[k];
	lztag[k<<1]=lztag[k];
	lztag[(k<<1)|1]=lztag[k];
	lztag[k]=-1;
}/*
inline bool isused(int S,int l,int r,int k){//LR:指定区间
	if (!segt[k]) return 0;
	if (l==r&&l==S) return segt[k];
	int mid=(l+r)>>1;
	if (lztag[k]!=-1&&l!=r) pushdown(l,r,k);
	if (S<=mid) return isused(S,l,mid,k<<1);
	if (S>=mid+1) return isused(S,mid+1,r,(k<<1)|1);
}
inline void update(int L,int R,int l,int r,bool b,int k){
	if (L<=l&&r<=R){
		segt[k]=b;
		lztag[k]=b;
		return;
	}
	int mid=(l+r)>>1;
	if (lztag[k]!=-1&&l!=r) pushdown(l,r,k);
	if (L<=mid) update(L,R,l,mid,b,k<<1);
	if (R>=mid+1) update(L,R,mid+1,r,b,(k<<1)|1);
	segt[k]=segt[k<<1]|segt[(k<<1)|1];
}*/
inline void dfs(int u){//u:color
	if (u>n){
		++ans;
		return;
	}
	int cnt=0;
	if (!isused[loc[u][0]]&&!isused[loc[u][1]]){
		bool b=true;
		for (int i=loc[u][0];i<=loc[u][1];++i)
			if (isused[i]){
				b=false;
				break;
			}
		if (b){
			for (int i=loc[u][0];i<=loc[u][1];++i)
				isused[i]=1;
			dfs(u+1);
			for (int i=loc[u][0];i<=loc[u][1];++i)
				isused[i]=0;
		}
	}
	if (!isused[loc[u][1]]&&!isused[loc[u][2]]){
		bool b=true;
		for (int i=loc[u][1];i<=loc[u][2];++i)
			if (isused[i]){
				b=false;
				break;
			}
		if (b){
			for (int i=loc[u][1];i<=loc[u][2];++i)
				isused[i]=1;
			dfs(u+1);
			for (int i=loc[u][1];i<=loc[u][2];++i)
				isused[i]=0;
		}
	}
	if (!isused[loc[u][2]]&&!isused[loc[u][0]]){
		bool b=true;
		for (int i=loc[u][2];i<=n*3;++i)
			if (isused[i]){
				b=false;
				break;
			}
		if (b)
			for (int i=1;i<=loc[u][0];++i)
				if (isused[i]){
					b=false;
					break;
				}
		if (b){
		for (int i=loc[u][2];i<=n*3;++i)
			isused[i]=1;
		for (int i=1;i<=loc[u][0];++i)
			isused[i]=1;
		dfs(u+1);
		for (int i=loc[u][2];i<=n*3;++i)
			isused[i]=0;
		for (int i=1;i<=loc[u][0];++i)
			isused[i]=0;
		}
	}
}
int main(){
	freopen("arc.in","r",stdin);
	freopen("arc.out","w",stdout);
	memset(isused,0,sizeof(isused));
	n=read();
	if (n>14){
		puts("0");
		return;
	}
	for (int i=1;i<=n*3;++i)
		c[i]=read(),loc[c[i]].push_back(i);
	dfs(1);
	printf("%lld",ans);
	return 0;
}