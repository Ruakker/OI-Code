/*
	Author: Chocola4ever
	Date: 2021-04-22 13:55:35
	LastEditTime: 2021-04-22 14:13:40
	FilePath: \Programs\20210422\chefteam.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
using namespace std;
ull n,k,ans=1,cnt=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		ans=1,cnt=1;
		cin>>n>>k;
		if (k>n){
			cout<<0<<endl;
			continue;
		}
		if (k==n){
			cout<<1<<endl;
			continue;
		}
		k=min(k,n-k);
		for (ull i=n;i>=n-k+1;--i){
			ull temp=i;
			while (cnt<=k&&temp%cnt==0)
				temp/=cnt,++cnt;
			ans*=temp;
			while (cnt<=k&&ans%cnt==0)
				ans/=cnt,++cnt;
		}
		for (ull i=cnt;i<=k;++i)
			ans/=i;
		cout<<ans<<endl;
	}
	return 0;
}
