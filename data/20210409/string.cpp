/*
	Author: Chocola4ever
	Date: 2021-04-09 08:46:22
	LastEditTime: 2021-04-09 16:21:01
	FilePath: \Programs\20210409\string.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=3e4+5;
inline ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-')
			w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
int num1[N],num2[N];
bool b;
int main(){
	// freopen("string.in","r",stdin);
	// freopen("string.out","w",stdout);
	int T=read();
	while (T--){
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		char s1[N],s2[N],news1[N],news2[N];
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		if (s1[1]=='*'){
			puts("No");
			continue;
		}
		int len1=strlen(s1+1),len2=strlen(s2+1),cnt1=0,cnt2=0;
		for (int i=1;i<=len1;++i)
			if (s1[i]!=s1[i-1]&&s1[i]!='*'&&s1[i-1]!='*'){
				news1[++cnt1]=s1[i];
				++num1[cnt1];
			}else if (s1[i]!='*') ++num1[cnt1];
		for (int i=1;i<=len2;++i)
			if (s2[i]!=s2[i-1]){
				news2[++cnt2]=s2[i];
				++num2[cnt2];
			}else ++num2[cnt2];
		// puts(news1+1);
		// puts(news2+1);
		// for (int i=1;i<=cnt1;++i)
		// 	printf("%d ",num1[i]);
		// puts("");
		// for (int i=1;i<=cnt2;++i)
		// 	printf("%d ",num2[i]);
		// puts("");
		b=1;
		if (cnt1!=cnt2){
			puts("No");
			continue;
		}else for (int i=1;i<=cnt1;++i)
				if (num1>num2||news1[i]!=news2[i])
					b=0;
		if (b) puts("Yes");
		else puts("No");
	}
	return 0;
}
