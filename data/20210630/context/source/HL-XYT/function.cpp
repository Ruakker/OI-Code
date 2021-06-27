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
int tot,n;
int isp[maxn],P[maxn],f[maxn],ans[maxn];
//int kkk[maxn]={0,2,3,5,7,11,13,17,19,23,29,31};
//int kk[maxn]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
void shai(int n)
{
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!isp[i])	
		{
			P[++tot]=i;
//			if(tot>11)
				if(tot%2==0 || tot<=7) f[i]=-1;
					else f[i]=1; 
		}		
		for(int j=1;j<=tot && i*P[j]<=n;j++)
		{
			isp[i*P[j]]=1;
			f[i*P[j]]=f[P[j]]*f[i];
			if(i%P[j]==0) break;
		} 
	}
	return ; 
} 
ll mn=1000000;
void print(int x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

void solve()
{
	shai(n);
	ll sum=0,mx=0;
	for(int i=1;i<=n;i++) 
	{
		print(f[i]);putchar(' ');
//		sum+=f[i]; mx=max(mx,abs(sum));
	}
//	printf("%lld\n",mx);
//	if(mx<mn) 
//	{
//		mn=mx;
//		for(int i=1;i<=11;i++) ans[i]=f[kkk[i]];
//	}
}
//void init()
//{
//	for(int i=1;i<=11;i++) f[kkk[i]]=kk[i];
//	solve();
//}
//void dfs(int x)
//{
//	if(x>11) {solve(); return ;}
//	f[kkk[x]]=-1;
//	dfs(x+1);
//	f[kkk[x]]=1;
//	dfs(x+1);
// } 
int main()
{
    freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
//	srand((unsigned int)time(0)); 
//	n=1000000;
	n=read();
	solve();
//	init(); 
//	dfs(1);
//	printf("%d\n",mn);
//	for(int i=1;i<=11;i++) printf("%d ",ans[i]);
	return 0;
}

/*
1 -1 -1 1 -1 
*/
