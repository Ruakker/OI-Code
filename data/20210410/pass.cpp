/*
	Author: Chocola4ever
	Date: 2021-04-10 08:15:33
	LastEditTime: 2021-04-10 13:21:06
	FilePath: \Programs\20210410\pass.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1;
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
	freopen("pass.in","r",stdin);
	freopen("pass.out","w",stdout);
	int T=read();
	while (T--){
		int x=read(),y=read(),a=read(),b=read();
		bool t=0;
		for (int i=0;i<=100;++i){
			if (a*x+b*y+(100-a-b)*i>=6000){
				printf("%d\n",i);
				t=1;
				break;
			}
		}
		if (t) continue;
		else puts("poor little A!");
	}
	return 0;
}
