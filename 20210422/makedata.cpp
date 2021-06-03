/*
	Author: Chocola4ever
	Date: 2021-04-22 15:52:30
	LastEditTime: 2021-04-22 15:57:54
	FilePath: \Programs\20210422\makedata.cpp
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
	freopen("data.in","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cout<<"1\n1000 3 6 2\n";
	for (int i=1;i<=1000;++i)
		//cout<<(int)(rand()&1)<<' '<<(int)(rand()&1)<<' '<<(int)(rand()&1)<<endl;
		cout<<"1 1 1\n";
	return 0;
}
