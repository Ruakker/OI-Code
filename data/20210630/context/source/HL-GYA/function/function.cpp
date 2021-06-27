#include<bits/stdc++.h>
#define int long long
#define rint register int
#define rep(i,a,b) for(rint (i)=(a);(i)<=(b);++(i))
#define per(i,a,b) for(rint (i)=(a);(i)>=(b);--(i))
inline int read()
{
	rint f=1,x=0; char c=getchar();
	while(c<'0'||c>'9') f=c=='-'?-1:1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return f*x;
}
inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return void();
}
using namespace std;
const int N=1e6+520,INF=1e15+520;
int n,cnt,f[N],p[N];
int sum[N],maxx;
bool vis[N];
inline void init()
{
	cnt=0;
	rep(i,1,n) f[i]=vis[i]=0;
	f[1]=1;
	int res=1;
	rep(i,2,n)
	{
		if(!vis[i])
		{
			p[++cnt]=i;
		    f[i]=(i%3!=1)?-1:1;
		}
		for(rint j=1;j<=cnt&&p[j]*i<=n;++j)
		{
			f[p[j]*i]=f[p[j]]*f[i];
			vis[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
	maxx=0;
	rep(i,1,n) sum[i]=sum[i-1]+f[i],maxx=max(maxx,abs(sum[i]));
	return void();
}
signed main()
{
	//freopen("function.in","r",stdin);
	//freopen("function.out","w",stdout);
	n=read();
	init();
	rep(i,1,n) write(f[i]),putchar(' ');
	return 0;
}
//1000000
