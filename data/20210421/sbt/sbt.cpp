#include<bits/stdc++.h>
#define ll long long
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
ll a,b;
void gcd(ll a,ll b){
	while (a!=b){
		if (a>b){
			a-=b;
			putchar('R');
		}else{
			b-=a;
			putchar('L');
		}
	}
}
signed main(){
	freopen("sbt.in","r",stdin);
	freopen("sbt.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b;
	gcd(a,b);
	return 0;
}