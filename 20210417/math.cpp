/*
	Author: Chocola4ever
	Date: 2021-04-17 08:53:10
	LastEditTime: 2021-04-17 14:46:22
	FilePath: \Programs\20210417\math.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5;
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
inline ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
inline void write(ll x){
	static int sta[35];
	ll top=0;
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while (top)
		putchar(sta[--top]+48);
}
int n;
ll ans=1,a[N],lcm=1;
signed main(){
//	freopen("math.in","r",stdin);
	//freopen("math.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i)
		a[i]=read(),ans*=a[i],lcm=lcm/gcd(lcm,a[i])*a[i];
	write(ans-lcm);
	return 0;
}
