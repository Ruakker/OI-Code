/*
	Author: Chocola4ever
	Date: 2021-04-18 16:54:27
	LastEditTime: 2021-04-18 16:57:16
	FilePath: \Programs\20210418\t.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e6+5,mod=1e9+7;
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
int n,m;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	n=read(),m=read();
	ll f[N],tot=0,p=m;
    int pos=1;
    for (int i=2; i <= n; i++) {
        while ((pos<< 1) < i)
			tot = (tot*m+f[++pos])%mod, p = p * m % mod;
        f[i] = (p - tot + mod) % mod;
    }
	printf("%lld\n",f[n]);
	return 0;
}
