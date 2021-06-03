/*
	Author: Chocola4ever
	Date: 2021-04-10 07:59:32
	LastEditTime: 2021-04-10 08:15:14
	FilePath: \Programs\20210410\add.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=10;
char s1[N],s2[N];
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int len1=strlen(s1+1),len2=strlen(s2+1);
	bool allnum=1;
	for (int i=1;i<=len1;++i)
		if (!isdigit(s1[i])) allnum=0;
	for (int i=1;i<=len2;++i)
		if (!isdigit(s2[i])) allnum=0;
	if (allnum){
		int i1=1,i2=1,num1=0,num2=0;
		for (int i=1;i<=len1;++i)
			num1=num1*10+s1[i]-'0';
		for (int i=1;i<=len2;++i)
			num2=num2*10+s2[i]-'0';
		printf("%d\n",num1+num2);
	}else{
		for (int i=1;i<=len1;++i)
			putchar(s1[i]);
		for (int i=1;i<=len2;++i)
			putchar(s2[i]);
		putchar('\n');
	}
	return 0;
}
