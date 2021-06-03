/*
	Author: Chocola4ever
	Date: 2021-04-22 20:36:32
	LastEditTime: 2021-04-22 20:36:33
	FilePath: \Programs\20210422\colltime.cpp
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
int s[N],v[N];
vector<int> t[41];//+20
void init(){}
int main(){
	for (int _=read();_--;){
		init();
		n=read();
		for (int i=1;i<=n;++i){
			s[i]=read(),v[i]=read();
			t[v[i]+20].push_back(s[i]);
		}
		for (int i=0;i<=40;++i)
			sort(t[i].begin(),t[i].end());
		for (int i=1;i<=n-1;++i)
			for (int j=i+1;j<=n;++j)
	}
	return 0;
}