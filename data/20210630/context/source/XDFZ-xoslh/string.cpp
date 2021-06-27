#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,S,T,sum;
vector<ll> ans;
void solve(){
	for(int i=S;i>=2;i--)
		while(i*(i-1)<=T) ans.push_back(i),T-=(i*(i-1)),sum+=i;
}
void work(){
	ans.clear(),sum=0;
	cin>>n; 
	n<<=1;
	S=sqrt(n)+1;
	while(S*(S-1)<n) S++;
	T=S*(S-1)-n;
	solve();
//	cout<<T<<' '<<S-sum<<'\n';
	for(int i=sum+1;i<=S;i++) ans.push_back(1);
	bool a=0;
	for(int i : ans){
		for(int j=1;j<=i;j++) cout<<a;
		a^=1;
	}
	cout<<'\n';
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T; cin>>T;
	while(T--) work();
}
