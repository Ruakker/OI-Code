/*
	Author: Ruakker
	Date: 2021-04-29 22:31:59
	LastEditTime: 2021-05-07 23:07:04
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
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
signed main(){
	for (int T=read();T--;){
		int a=read(),b=read();
		if (b==1){
			puts("NO");
			continue;
		}
		if (b==2){
			printf("YES\n%lld %lld %lld\n",a*b*2-a,a,a*b*2);
			continue;
		}
		int z=a*b,y=(b-1)*a,x=z-y;
		printf("YES\n%lld %lld %lld\n",x,y,z);
	}
	return 0;
}
