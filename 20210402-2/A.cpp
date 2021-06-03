/*
	Author: Chocola4ever
	Date: 2021-04-02 18:03:26
	LastEditTime: 2021-04-02 18:10:02
	FilePath: \Programs\20210402-2\A.cpp
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
int main(){
	int a[N],b[N];
	int T=read();
	while (T--){
		int n=read();
		for (int i=1;i<=n;++i)
			a[i]=read();
		for (int i=1;i<=n;++i)
			b[i]=read();
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		int j=1,ans=0;
		for (int i=1;i<=n;++i){
			while (b[j]<a[i]&&j<=n) ++j;
			if (j>n) break;
			++ans,++j;
		}
		printf("%d\n",ans);
	}
	return 0;
}
