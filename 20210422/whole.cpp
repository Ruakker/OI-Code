/*
	Author: Chocola4ever
	Date: 2021-04-22 14:17:28
	LastEditTime: 2021-04-22 20:39:07
	FilePath: \Programs\20210422\whole.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define ull long long
#define inf 0x3f3f3f3f
// #define Debug
using namespace std;
const int N=5005;
const ll Mod=1000000080798150871;//18
int n,m,l,k;
ull c[N][N];
int a[N][N];
void init(){
	c[0][0]=1;
	for (int i=1;i<=N-5;++i)
		for (int j=1;j<=i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%Mod;
}
int main(){
	// freopen("data.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	init();
	#ifdef Debug
	for (int i=1;i<=10;++i){
		for (int j=1;j<=i;++j)
			cout<<c[i][j]<<' ';
		cout<<endl;
	}
	#endif
	while (T--){
		cin>>n>>m>>l>>k;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j){
				char c;
				cin>>c;
				a[i][j]=c-'0';
			}
		ull cnt=0,ans=0;
		if (k==1){
			for (int i=1;i<=m;++i){
				cnt=0;
				for (int j=1;j<=n;++j)
					if (a[j][i]) ++cnt;
				ans=(ans+c[cnt+1][l+1])%Mod;
				#ifdef Debug
					cout<<cnt<<' '<<l<<endl;
				#endif
			}
			cout<<ans<<endl;
			continue;
		}
		if (k==2){
			for (int i1=1;i1<=m-1;++i1)
				for (int i2=i1+1;i2<=m;++i2){
					cnt=0;
					for (int j=1;j<=n;++j)
						if (a[j][i1]&&a[j][i2]) ++cnt;
					ans=(ans+c[cnt+1][l+1])%Mod;
					#ifdef Debug
						cout<<cnt<<' '<<l<<endl;
					#endif
				}
			cout<<ans<<endl;
			continue;
		}
		if (k==3){
			cnt=0;
			for (int j=1;j<=n;++j)
				if (a[j][1]&&a[j][2]&&a[j][3]) ++cnt;
			ans=(ans+c[cnt+1][l+1])%Mod;
			#ifdef Debug
				cout<<cnt<<' '<<l<<endl;
			#endif
		}
		cout<<ans<<endl;
		continue;
	}
	return 0;
}
/*
10 3 2 3
1 1 1
0 1 1
0 0 1
1 0 1
0 1 1
0 0 1
1 1 1
1 1 1
0 1 1
1 1 1
0 0 1

C(4,2)=6
*/