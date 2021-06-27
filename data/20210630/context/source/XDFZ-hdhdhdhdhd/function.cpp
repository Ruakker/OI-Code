/*---Author:HenryHuang---*/
/*---Never Settle---*/
/*---Never Enough---*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int f[maxn],p[maxn],pri[maxn],cnt;
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n=1e6;
	int ans=20;
	f[1]=1;
	int sum=1,mx=1;
	memset(p,0,sizeof p);cnt=0;
	for(int i=2;i<=n;++i){		// cerr<<mx[1]<<' '<<mn[1]<<'\n';
		if(!p[i]){
			pri[++cnt]=i;
			if(i%3==1) f[i]=1;
			else f[i]=-1;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j){
			p[i*pri[j]]=1;
			f[i*pri[j]]=f[i]*f[pri[j]];
			// if(owo) update(i*pri[j],n,1,n,f[i*pri[j]],1);
			if(i%pri[j]==0) break;
		}
		// for(int j=1;j*j<=i;++j){
		// 	if(i%j==0){
		// 		if(f[j]*f[i/j]!=f[i]){
		// 			// cerr<<j<<' '<<i/j<<' '<<f[i]<<'\n';
		// 			// cerr<<"ERR";
		// 			return 0;
		// 		}
		// 	}
		// }
		sum+=f[i];
		mx=max(abs(sum),mx);
	}
	if(mx<ans){
		ans=mx;
	}
	for(int i=1;i<=n;++i){
		cout<<f[i]<<' ';
	}	
	cout<<'\n';
	// cerr<<ans<<'\n';
	// cerr<<qwq<<'\n';
	return 0;
}