/*
	Author: Ruakker
	Date: 2021-05-07 21:07:51
	LastEditTime: 2021-05-10 21:37:39
	Description: Scanline
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
const int N=1e5+5,maxn = 1 << 31;
int n,disc[N<<1];
ll ans;
struct Ruakker{	//the operations to do
	int l,r,y,val;
}opt[N<<1];
struct Rekkaur{
	int len,cnt;
}segt[N<<3];
bool cmp(Ruakker a,Ruakker b){return a.y<b.y;}
void pushup(int l,int r,int k){
	if (segt[k].cnt)
		segt[k].len=r-l;else
		segt[k].len=segt[k<<1].len+segt[k<<1|1].len;
}
// void pushup(int rt){
// 	if (t[rt].cnt) t[rt].len = val[t[rt].r + 1] - val[t[rt].l];
// 	else t[rt].len = t[ls].len + t[rs].len;
// }//向上更新节点
inline void add(int L,int R,int l,int r,int num,int k){
	if (L==l&&r==R){
		segt[k].cnt+=num,pushup(l,r,k);
		return;
	}
	int mid=l+r>>1;
	if (L<=mid) add(L,R,l,mid,num,k<<1);
	if (mid+1<=R) add(L,R,mid+1,r,num,k<<1|1);
	pushup(l,r,k);
}

signed main(){
	n=read();
	for (int i=1;i<=n;++i){
		int x_1=read(),x_2=read(),y_1=read(),y_2=read();
		opt[i]=(Ruakker){x_1,x_2,y_1,1};
		opt[i+n]=(Ruakker){x_1,x_2,y_2,-1};
		disc[i]=y_1,disc[i+n]=y_2;
	}
	n<<=1,	//make process much easier :)
	sort(disc+1,disc+1+n),	//discretization
	sort(opt+1,opt+1+n,cmp);
	for (int i=1;i<n;++i)
		ans+=(opt[i+1].y-opt[i].y)*segt[1].len,
		add(opt[i].l,opt[i].r,1,n,opt[i].val,1);
	printf("%lld\n",ans);
	return 0;
}
