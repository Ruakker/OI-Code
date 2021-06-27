/*
	Author: Ruakker
	Date: 2021-05-13 20:52:45
	LastEditTime: 2021-05-14 09:03:46
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
inline ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
void write(ll x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
inline void writeln(ll x){write(x),putchar('\n');}
const int N=1e5+5;
struct Ruakker{
	int sz,son[2],val,weight;
	bool rev;
}tr[N];
int tot,n,m,rt,a,b,c,d;
inline int newnode(int val){return tr[++tot].sz=1,tr[tot].son[0]=tr[tot].son[1]=0,tr[tot].val=val,tr[tot].weight=rand(),tr[tot].rev=0,tot;}
inline void update(int cur){	//here we not only recalc the size of the node, but also reverse the son of the node :)
	tr[cur].sz=tr[tr[cur].son[0]].sz+tr[tr[cur].son[1]].sz+1;
	if (cur&&tr[cur].rev){
		tr[cur].rev^=1;
		std::swap(tr[cur].son[0],tr[cur].son[1]);
		tr[tr[cur].son[0]].rev^=1,tr[tr[cur].son[1]].rev^=1;
	}
}

int merge(int x,int y){
	if (!x||!y) return x+y;
	update(x),update(y);
	if (tr[x].weight<tr[y].weight)
		return tr[x].son[1]=merge(tr[x].son[1],y),update(x),x;else
		return tr[y].son[0]=merge(x,tr[y].son[0]),update(y),y;
}
void split(int cur,int size,int &x,int &y){	//notice that this time the split is depending on the size of the tree
	if (!cur) return x=y=0,void();
	update(cur);
	if (tr[tr[cur].son[0]].sz>=size)	//if the left-son tree's size is larger,then
		y=cur,split(tr[cur].son[0],size,x,tr[cur].son[0]);else
		x=cur,split(tr[cur].son[1],size-tr[tr[cur].son[0]].sz-1,tr[cur].son[1],y);
	update(cur);
}
inline void ins(int val){split(rt,val,a,b),rt=merge(merge(a,newnode(val)),b);}

inline void rev(int l,int r){
	split(rt,r,a,b),split(a,l-1,c,d);		//the tree_d is the interval [l,r]
	tr[d].rev^=1,rt=merge(merge(c,d),b);	//reverse the interval and merge it :)
}

void print(int cur){
    if (!cur) return;
	update(cur);
    print(tr[cur].son[0]);
    if (tr[cur].val>=1&&tr[cur].val<=n)
		write(tr[cur].val),putchar(' ');
    print(tr[cur].son[1]);
}

signed main(){
	srand(time(0));
	n=read(),m=read();
	for (int i=1;i<=n;ins(i++));
	for (;m--;rev(read(),read()));
	for (;m--;){
		int l=read(),r=read();
		rev(l,r);
	}
	print(rt),putchar('\n');
	return 0;
}
