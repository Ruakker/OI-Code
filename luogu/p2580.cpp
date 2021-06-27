/*
	Author: Chocola4ever
	Date: 2021-04-28 17:53:34
	LastEditTime: 2021-04-28 18:15:44
	FilePath: \HydroOJd:\Programs\P2580.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=5e6+5;
char s[55];
int trie[N][26],tot=0,ed[N],n,m;//ed:1-already;0-not already;-1-none
void insert(char *s){
	int p=0,len=strlen(s);
	for (int i=0;i<len;++i){
		int ch=s[i]-'a';
		if (trie[p][ch]==0)
			trie[p][ch]=++tot;
		p=trie[p][ch];
	}
	ed[p]=0;
}
int search(char *s){
	int p=0,len=strlen(s);
	for (int i=0;i<len;++i){
		int ch=s[i]-'a';
		if (!trie[p][ch]) return -1;
		p=trie[p][ch];
	}
	if (ed[p]==0){
		ed[p]=1;
		return 0;
	}else return ed[p];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(ed,-1,sizeof ed);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>s,insert(s);
	cin>>m;
	for (int i=1;i<=m;++i){
		cin>>s;
		int temp=search(s);
		if (temp==-1)
			puts("WRONG");
		if (temp==1)
			puts("REPEAT");
		if (temp==0)
			puts("OK");
	}
	return 0;
}
