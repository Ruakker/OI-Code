#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n;
		for(int i=2;;i++)
		{
			if(n<=1ll*i*(i-1)/2)
			{
				m=i;
				break;
			}
		}
		int ff=0,x=1ll*m*(m-1)/2-n,he=0;
		for(int i=m;i>=1&&he<m;)
		{
			if(1ll*i*(i-1)/2<=x)
			{
				for(int j=1;j<=i;j++)printf("%d",ff);
				he+=i;
				ff=!ff;
				x-=1ll*i*(i-1)/2;
			}else i--;
		}
		printf("\n");
	}
	return 0;
}
