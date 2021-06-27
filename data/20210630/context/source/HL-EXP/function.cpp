#include<bits/stdc++.h>
using namespace std;
int s[1000005],d[1000005],f[1000005],tot=0;
void print()
{
	s[1]=f[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!s[i])d[++tot]=i,f[i]=-1;
		for(int j=1;j<=tot&&i*d[j]<=1000000;j++)
		{
			s[i*d[j]]=1,f[i*d[j]]=-f[i];
			if(i%d[j]==0)break;
		}
	}
}
int main()
{
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	print();
	int n,ss=0,mx=0;
	cin>>n;
	for(int i=1;i<n;i++)printf("%d ",f[i]);
	printf("%d\n",f[n]);
	return 0;
}
