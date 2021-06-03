/*
	Author: Ruakker
	Date: 2021-05-07 18:43:10
	LastEditTime: 2021-05-07 20:57:24
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define lson segt[k].left
#define rson segt[k].right
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
const int N=2e5+5,M=1e7;
int n,rt=1,tot=1;
map<int,int> mp;
struct Ruakker{
	int left,right,val;
}segt[N<<6];
inline void Insert(int l,int r,int num,int &k){
	if (!k) k=++tot,segt[k].val=lson=rson=0;
	++segt[k].val;
	if (l>=r) return;
	int mid=l+r>>1;
	if (num<=mid) Insert(l,mid,num,lson);
	else Insert(mid+1,r,num,rson);
}
inline void Delete(int l,int r,int num,int k){
	--segt[k].val;
	if (l>=r) return;
	int mid=l+r>>1;
	if (num<=mid) Delete(l,mid,num,lson);
	else Delete(mid+1,r,num,rson);
}
inline int getrank(int L,int R,int l,int r,int k){
	if (L<=l&&r<=R) return segt[k].val;
	int mid=l+r>>1,sum=0;
	if (L<=mid) sum+=getrank(L,R,l,mid,lson);
	if (mid+1<=R) sum+=getrank(L,R,mid+1,r,rson);
	return sum;
}
inline int getnum(int l,int r,int kth,int k){
	if (l>=r) return l;
	int mid=l+r>>1;
	if (segt[lson].val>=kth) return getnum(l,mid,kth,lson);
	else return getnum(mid+1,r,kth-segt[lson].val,rson);
}
signed main(){
	n=read();
	for (int i=1;i<=n;++i){
		int opt=read(),x=read();
		if (opt==1) Insert(1,M<<1,x+M,rt),++mp[x];
		if (opt==2) Delete(1,M<<1,x+M,rt),(--mp[x]==0)?mp.erase(x):0;
		if (opt==3) printf("%d\n",getrank(1,x+M-1,1,M<<1,rt)+1);
		if (opt==4) printf("%d\n",getnum(1,M<<1,x,rt)-M);
		if (opt==5) printf("%d\n",((--mp.lower_bound(x))->first));
		if (opt==6) printf("%d\n",((mp.upper_bound(x))->first));
	}
	return 0;
}