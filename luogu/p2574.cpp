/*
	Author: Ruakker
	Date: 2021-04-30 12:04:14
	LastEditTime: 2021-05-04 18:05:59
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
const int N=2e5+5;
char s[N];
int n,m,a[N],segt[N<<2],lztag[N<<2];
void pushdown(int l,int r,int k){
	if (lztag[k]&&l!=r){
		int mid=l+r>>1;
		segt[k<<1]=mid-l+1-segt[k<<1],lztag[k<<1]^=1,
		segt[k<<1|1]=r-mid-segt[k<<1|1],lztag[k<<1|1]^=1;
		lztag[k]=0;
	}
}
inline void build(int l,int r,int k){
	if (l>=r) return segt[k]=a[l],void();
	int mid=l+r>>1;
	build(l,mid,k<<1),build(mid+1,r,k<<1|1);
	segt[k]=segt[k<<1]+segt[k<<1|1];
}
inline void Reverse(int L,int R,int l,int r,int k){
	if (L<=l&&r<=R) return segt[k]=r-l+1-segt[k],lztag[k]^=1,void();
	pushdown(l,r,k);
	int mid=l+r>>1;
	if (L<=mid) Reverse(L,R,l,mid,k<<1);
	if (mid+1<=R) Reverse(L,R,mid+1,r,k<<1|1);
	segt[k]=segt[k<<1]+segt[k<<1|1];
}
inline ll getsum(int L,int R,int l,int r,int k){
	if (L<=l&&r<=R) return segt[k];
	pushdown(l,r,k);
	ll mid=l+r>>1,sum=0;
	if (L<=mid) sum+=getsum(L,R,l,mid,k<<1);
	if (mid+1<=R) sum+=getsum(L,R,mid+1,r,k<<1|1);
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s+1;
	for (int i=1;i<=n;++i)
		a[i]=s[i]-'0';
	build(1,n,1);
	for (int i=1;i<=m;++i){
		int opt,l,r;
		cin>>opt>>l>>r;
		if (opt) cout<<getsum(l,r,1,n,1)<<endl;
		else Reverse(l,r,1,n,1);
		// for (int i=1;i<=n;++i)
		// 	cout<<getsum(i,i,1,n,1)<<' ';
		// cout<<endl;
	}
	return 0;
}