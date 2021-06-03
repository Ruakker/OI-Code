/*
	Author: Ruakker
	Date: 2021-05-11 18:24:15
	LastEditTime: 2021-05-11 20:11:29
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
const int N=1005,Times=1e5;
int n,x_,y_;
std::pii a[N];
std::vector<std::pii> k;
signed main(){
	freopen("geo.in","r",stdin),freopen("geo.out","w",stdout);
	for (int T=read();T--;){
		n=read(),k.clear();
		for (int i=1;i<=n;++i)
			x_=read(),y_=read(),a[i]=std::mp(x_,y_);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)if (i!=j){
				double kk=((a[i].y-a[j].y)/(double)(a[i].x-a[j].x));
				k.push_back(
					std::mp(
						(int)(kk*Times),
						(int)((-kk*a[i].x+a[i].y)*Times)
					)
				);
				// printf("%lld,%lld:%lld %lld\n",i,j,(int)(kk*Times),(int)((-kk*a[i].x+a[i].y)*Times));
			}
		sort(k.begin(),k.end());
		int cnt=1;
		bool temp=0;
		for (int i=1;i<k.size();++i){
			if (k[i]==k[i-1]) ++cnt;
			else cnt=0;
			if (cnt>=n){
				puts("YES");
				temp=1;
				break;
			}
		}
		if (!temp){
			int cntt=0;
			for (int i=1;i<k.size();++i)
				if (k[i].first==0) ++cntt;
			if (cntt>=n) puts("YES");else
			puts("NO");
		}
		// for (int i=1;i<=n;++i)
		// 	printf("/kk:%lld %lld\n",k[i].first,k[i].second);
	}
	return 0;
}
