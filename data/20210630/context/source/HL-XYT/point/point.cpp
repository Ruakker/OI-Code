
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
int main()
{
    freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int n=read(),d=read(),a=read(),b=read();
	printf("%d\n",n*a); 
	return 0;
}
 
