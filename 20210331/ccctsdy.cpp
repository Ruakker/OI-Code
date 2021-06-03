/*
	Author: Chocola4ever
	Date: 2021-03-31 15:37:05
	LastEditTime: 2021-03-31 17:38:35
	FilePath: \Programs\20210331\ccctsdy.cpp
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
stack<int> st;
int main(){
	freopen("ccctsdy.in","r",stdin);
	freopen("ccctsdy.out","w",stdout);
	ll cnt=0,n=read();
	int ans[N];
	for (int i=0;n>0;n>>=1)
		if (n&1)
			st.push(++i),ans[++cnt]=++i;
		else
			if (!st.empty())
				ans[++cnt]=st.top(),st.pop();
			else ans[++cnt]=++i;
	for (int i=1;i<=cnt;++i)
		printf("%d ",ans[i]);
	for (;!st.empty();st.pop())
		printf("%d ",st.top());
	return 0;
}