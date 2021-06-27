#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
ll read() 
{
	ll res=0,f=1;
	char c=getchar();
	while(!isdigit(c) && c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) res=(res<<1)+(res<<3)+c-48,c=getchar();
	return res*f;
}
bool bl;
int n,m;
int sum[maxn],a[maxn];
void dfs(int x)
{
	if(bl) return ; 
	if(x>m) 
	{
//		for(int i=1;i<=m;i++) printf("%d",a[i]); puts("");
		sum[0]=0;
		for(int i=1;i<=m;i++) sum[i]=sum[i-1]+a[i];
		int tot=0;
		for(int i=1;i<m;i++) 
			for(int j=i+1;j<=m;j++)
				if(abs(sum[j]-sum[i-1])!=j-i+1) tot++;
		if(tot==n) 
		{
			for(int i=1;i<=m;i++) printf("%d",a[i]==1?1:0); puts("");
			bl=1;
		 } 
		return;
	}
	a[x]=-1;
	dfs(x+1);
	a[x]=1;
	dfs(x+1);
}
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		m=1; bl=0;
		while(m*(m-1)/2<n) m++;
		dfs(1);
	}
	return 0;
}
 
