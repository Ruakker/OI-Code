/*
	Author: Chocola4ever
	Date: 2021-04-28 09:39:57
	LastEditTime: 2021-04-28 14:55:23
	FilePath: \Programs\20210428\choose.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
// #define int long long
using namespace std;
const int N=4e6+5;
int trie[N][30],sm[N];
int n,ans=0,tot=0;
string s;
void insert(){
	int p=0,len=s.size();
	for (int i=0;i<len;++i){
		int ch=s[i]-'a';
		if (trie[p][ch]==0)
			trie[p][ch]=++tot;
		p=trie[p][ch];
		++sm[p];
	}
}
void search(){
	int p=0,len=s.size();
	for (int i=0;i<len;++i){
		int ch=s[i]-'a';
		if (!trie[p][ch]) break;
		p=trie[p][ch];
		if (sm[p]) --sm[p],++ans;
	}
}
signed main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>s,insert();
	for (int i=1;i<=n;++i)
		cin>>s,search();
	cout<<ans<<endl;
	return 0;
}
