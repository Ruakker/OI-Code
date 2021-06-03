/*
	Author: Chocola4ever
	Date: 2021-04-11 08:04:04
	LastEditTime: 2021-04-11 09:39:18
	FilePath: \Programs\20210411\conjecture.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e7+5;
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
int a[N],b[N];
int main(){
	freopen("conjecture.in","r",stdin);
	freopen("conjecture.out","w",stdout);
	while (1){
		memset(a,-1,sizeof a);
		memset(b,-1,sizeof b);
		int A=read(),B=read();
		if (A==0&&B==0) break;
		int a_=A,b_=B;
		int cntA=0,cntB=0;
		a[A]=b[B]=0;
		bool gobreak=0;
		while (A!=1&&B!=1){
			if (A&1) A=((A<<1)|1)+A;
			else A>>=1;
			a[A]=++cntA;
			if (B&1) B=((B<<1)|1)+B;
			else B>>=1;
			b[B]=++cntB;
			if (b[A]!=-1){
				printf("%d needs %d steps, %d needs %d steps, they meet at %d\n",a_,cntA,b_,b[A],A);
				gobreak=1;
				break;
			}else
			if (a[B]!=-1){
				printf("%d needs %d steps, %d needs %d steps, they meet at %d\n",a_,a[B],b_,cntB,B);
				gobreak=1;
				break;
			}
		}
		if (gobreak) continue;
		while (A!=1){
			if (A&1) A=((A<<1)|1)+A;
			else A>>=1;
			a[A]=++cntA;
			if (b[A]!=-1){
				printf("%d needs %d steps, %d needs %d steps, they meet at %d\n",a_,cntA,b_,b[A],A);
				break;
			}
		}
		while (B!=1){
			if (B&1) B=((B<<1)|1)+B;
			else B>>=1;
			b[B]=++cntB;
			if (a[B]!=-1){
				printf("%d needs %d steps, %d needs %d steps, they meet at %d\n",a_,a[B],b_,cntB,B);
				break;
			}
		}
	}
	return 0;
}
