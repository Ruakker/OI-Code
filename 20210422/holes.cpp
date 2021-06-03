/*
	Author: Chocola4ever
	Date: 2021-04-22 13:40:14
	LastEditTime: 2021-04-22 13:45:51
	FilePath: \Programs\20210422\holes.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=200;
int a[]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		char s[N];
		cin>>s+1;
		int n=strlen(s+1);
		int ans=0;
		for (int i=1;i<=n;++i)
			ans+=a[s[i]-'A'];
		cout<<ans<<endl;
	}
	return 0;
}
/*
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0
*/