#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=100,S=500000;
int x[N],y[N],f[N][S];
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
inline int dist(int a,int b){
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
signed main(){
	int t=read();
	for (int _=1;_<=t;++_){
		int n=read(),m=0;
		for (int i=0;i<n;++i)
			x[m]=read(),y[m++]=read(),x[m]=read(),y[m++]=read();
		x[m]=0,y[m]=0;
		memset(f,127,sizeof(f));
		for (int i=0;i<m;++i)
			f[i][1<<i]=dist(i,m);
		for (register ll s=0;s<(1<<m);++s){
			int cnt=0,flg=0;
			for (int i=0;i<m;i+=2){
				if (!(s>>i&1)&&(s>>(i+1)&1))
					++cnt;
				if ((s>>i&1)&&!(s>>(i+1)&1))
					++flg;
			}
			if (cnt>2||flg)
				continue;
			for (int i=0;i<m;++i)
				if (s>>i&1)
					for (int j=0;j<m;++j)
						if (!(s>>j&1))
							f[j][s^(1<<j)]=min(f[j][s^(1<<j)],f[i][s]+dist(i,j));
		}
		int ans=1e9;
		for (int i=1;i<m;++i)
			ans=min(ans,f[i][(1<<m)-1]+dist(i,m));
		printf("%lld\n",ans);
	}
	return 0;
}