#include<bits/stdc++.h>
#define fre(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1;c=getchar(); }
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x*f;
}
int n,k,ans;
map<int,int>mp;
int main(){
	fre(music);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	int S=(1<<k)-1;
	int sum=0;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		char s[40];
		cin>>s;
		int x=0;
		for(int j=0;j<k;j++) x|=(s[j]=='A')<<j;
		sum^=x;
		x=sum;
		if(mp.find(x)==mp.end()) mp[x]=i;
		else ans=max(ans,i-mp[x]);
		if(mp.find(S^x)!=mp.end()) ans=max(ans,i-mp[S^x]);
	}
	printf("%d\n",ans);
	return 0;
}
