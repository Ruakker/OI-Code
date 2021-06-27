#include<bits/stdc++.h>
using namespace std;
int n,d,a,b,x[155],y[155],f[155],vist[155],bs[155],ds[155];
int check()
{
	sort(y+1,y+n+1);
	f[0]=0;
	int mn=-b*y[1];
	for(int i=1;i<=n;i++)
	{
		f[i]=a+b*y[i]+mn;
		mn=min(mn,f[i]-b*y[i+1]);
	}
	return f[n];
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>d>>a>>b;
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	n=unique(x+1,x+n+1)-x-1;
	if(d==0)
	{
		for(int i=1;i<=n;i++)y[i]=x[i];
		cout<<check()<<endl;
	}else if(n<=20)
	{
		int aa=INT_MAX;
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<j-1))y[j]=x[j]+d;
				else y[j]=x[j]-d;
			}
			aa=min(aa,check());
		}
		cout<<aa<<endl;
	}else if(a<=b)
	{
		int gs=0;
		for(int i=1;i<=n;i++)
		{
			if(vist[i])continue;
			gs++;
			for(int j=1;j<=n;j++)if(x[j]==x[i]+2*d)vist[j]=1;
		}
		cout<<gs*a<<endl;
	}else
	{
		double T=1e9;
		for(int i=1;i<=n;i++)bs[i]=ds[i]=1,y[i]=x[i]+d;
		int b=check(),dd=b;
		while(T>1e-3)
		{
			int t=rand()%n+1;
			ds[t]=-ds[t];
			for(int i=1;i<=n;i++)y[i]=x[i]+ds[i]*d;
			int g=check();
			if(g<b)
			{
				b=g;
				for(int i=1;i<=n;i++)bs[i]=ds[i];
			}
			if(g<dd)dd=g;
			else if(exp((dd-g)/T)>1.0*rand()/RAND_MAX)dd=g;
			else ds[t]=-ds[t],y[t]=x[t]+ds[t]*d;
			T*=0.9991;
		}
		cout<<b<<endl;
	}
	return 0;
}
