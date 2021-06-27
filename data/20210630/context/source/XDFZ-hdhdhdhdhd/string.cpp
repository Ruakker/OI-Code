/*---Author:HenryHuang---*/
/*---Never Settle---*/
/*---Never Enough---*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
int f[maxn],lst[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(f,63,sizeof f);
	f[0]=0;
	for(int i=2;i<=1000;++i){
		int val=i,w=i*(i-1)/2;
		for(int j=w;j<=maxn-5;++j){
			if(f[j]>f[j-w]+val){
				f[j]=min(f[j],f[j-w]+val);
				lst[j]=val;
			}
		}
	}
	ll T;cin>>T;
	while(T--){
		ll n;cin>>n;
		vector<pair<ll,ll> > ans;
		ll st=max(1ll,(ll)sqrt(n)-10);
		for(ll i=st;;++i){
			ll sum=1ll*i*(i-1)/2-n;
			if(sum<0) continue;
			if(f[sum]<=i){
				while(sum!=0){
					int x=lst[sum];
					ans.push_back(make_pair(x,1));
					sum-=x*(x-1)/2;
				}
			}
			int opt=0,num=0;
			for(ll o=0;o<ans.size();++o){
				for(ll j=1;j<=ans[o].second;++j){
					for(ll k=1;k<=ans[o].first;++k) cout<<opt,++num;
					opt^=1;
				}
			}
			while(num<i){
				cout<<opt;
				opt^=1;
				++num;
			}
			cout<<'\n';
			break;
		}
	}
	return 0;
}