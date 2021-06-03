/*
	Author: Chocola4ever
	Date: 2021-04-28 07:55:31
	LastEditTime: 2021-04-28 11:14:47
	FilePath: \Programs\20210428\queue.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
const int Mod=1000000007;
int n,a,b,c,d,e,ans=0;
inline void dfs(int pre,int k,int sum){	//pre:1-male,0-female
	if (k>n) return;
	if (k==n){
		ans=(ans+sum)%Mod;
		return;
	}
	if (pre==1){
		dfs(1,k+a,sum+d);
		dfs(0,k+b,sum+e);
	}else{
		dfs(1,k+b,sum+d);
		dfs(0,k+c,sum+e);
	}
}
signed main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>a>>b>>c>>d>>e;
	dfs(1,0,d);
	dfs(0,0,e);
	cout<<ans<<endl;
	return 0;
}
