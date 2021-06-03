/*
	Author: Ruakker
	Date: 2021-04-30 12:04:14
	LastEditTime: 2021-05-06 14:40:42
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
int n,m,a[N][25],segt[N<<2][25],lztag[N<<2][25];
void pushdown(int l,int r,int bit,int k){
	if (lztag[k][bit]&&l!=r){
		int mid=l+r>>1;
		segt[k<<1][bit]=mid-l+1-segt[k<<1][bit],lztag[k<<1][bit]^=1,
		segt[k<<1|1][bit]=r-mid-segt[k<<1|1][bit],lztag[k<<1|1][bit]^=1;
		lztag[k][bit]=0;
	}
}
inline void build(int l,int r,int bit,int k){
	if (l>=r) return segt[k][bit]=a[l][bit],void();
	int mid=l+r>>1;
	build(l,mid,bit,k<<1),build(mid+1,r,bit,k<<1|1);
	segt[k][bit]=segt[k<<1][bit]+segt[k<<1|1][bit];
}
inline void Xor(int L,int R,int l,int r,int bit,int k){
	if (L<=l&&r<=R) return segt[k][bit]=r-l+1-segt[k][bit],lztag[k][bit]^=1,void();
	pushdown(l,r,bit,k);
	int mid=l+r>>1;
	if (L<=mid) Xor(L,R,l,mid,bit,k<<1);
	if (mid+1<=R) Xor(L,R,mid+1,r,bit,k<<1|1);
	segt[k][bit]=segt[k<<1][bit]+segt[k<<1|1][bit];
}
inline ll getsum(int L,int R,int l,int r,int bit,int k){
	if (L<=l&&r<=R) return segt[k][bit];
	pushdown(l,r,bit,k);
	ll mid=l+r>>1,sum=0;
	if (L<=mid) sum+=getsum(L,R,l,mid,bit,k<<1);
	if (mid+1<=R) sum+=getsum(L,R,mid+1,r,bit,k<<1|1);
	return sum;
}
int main(){
	n=read();
	for (int i=1;i<=n;++i){
		a[i][0]=read();
		for (int j=1,temp=a[i][0];j<=20;++j,temp>>=1)
			a[i][j]=temp&1;
	}
	for (int i=1;i<=20;++i)
		build(1,n,i,1);
	m=read();
	for (int i=1;i<=m;++i){
		int opt=read(),l=read(),r=read();
		if (opt==1){
			ll sum=0;
			for (int i=20;i>=1;--i)
				sum=(sum<<1)+getsum(l,r,1,n,i,1);
			printf("%lld\n",sum);
		}else
			for (int j=1,temp=read();j<=20;++j,temp>>=1)
				if (temp&1) Xor(l,r,1,n,j,1);
		// for (int k=1;k<=n;++k){
		// 	ll sum=0;
		// 	for (int j=20;j>=1;--j)
		// 		sum=(sum<<1)+getsum(k,k,1,n,j,1);
		// 	printf("%lld ",sum);
		// }
		// puts("");
	}
	return 0;
}