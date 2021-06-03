/*
	Author: Chocola4ever
	Date: 2021-04-29 08:11:17
	LastEditTime: 2021-04-29 11:01:47
	FilePath: \HydroOJd:\Programs\20210429\game.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
inline ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
const int N=2e5+5;
struct Ruakker{
	int pos,v,a,up,down;
}car[N];
int n,l,mx=-inf,mxid;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),l=read();
	for (int i=1;i<=n;++i)
		car[i].pos=read();
	for (int i=1;i<=n;++i)
		car[i].v=read();
	for (int i=1;i<=n;++i){
		car[i].a=read();
		if (car[i].a>mx)
			mx=car[i].a,mxid=i;
	}
	for (int i=1;i<=n;++i)
		car[i].up=inf,car[i].down=1;
	car[mxid].up=-1,car[mxid].down=1;
	for (int i=1;i<=n-1;++i)
		for (int j=i+1;j<=n;++j){
			if (car[i].v==car[j].v||car[i].a==car[j].a) continue;
			int dis=abs(car[i].pos-car[j].pos),deltav=abs(car[i].v-car[j].v);
			if ((car[i].v<0&&car[j].v>0&&car[i].pos<car[j].pos)||
				(car[i].v>0&&car[j].v<0&&car[j].pos<car[i].pos)||
				(car[i].v-car[j].v<0&&car[i].pos<car[j].pos)||
				(car[j].v-car[i].v<0&&car[j].pos<car[i].pos))
				dis=l-abs(car[i].pos-car[j].pos);
			printf("i:%lld,j:%lld,dis:%lld,v:%lld\n",i,j,dis,deltav);
			if (car[i].a>car[j].a){
				if (dis/(double)deltav<car[j].up/car[j].down){
					car[j].up=dis,car[j].down=deltav;
					int temp=gcd(car[i].up,car[i].down);
					car[j].up/=temp,car[j].down/=temp;
				}
			}else{
				if (dis/(double)deltav<car[i].up/car[i].down){
					car[i].up=dis,car[i].down=deltav;
					int temp=gcd(car[i].up,car[i].down);
					car[i].up/=temp,car[i].down/=temp;
				}
			}
		}
	int mxup=0,mxdown=1;
	for (int i=1;i<=n;++i)
		if (mxup/(double)(mxdown)<car[i].up/(double)(car[i].down))
			mxup=car[i].up,mxdown=car[i].down,mxid=i;
	printf("%lld/%lld\n",mxup,mxdown);
	for (int i=1;i<=n;++i)
		cout<<car[i].up<<' '<<car[i].down<<endl;
	cout<<mxid<<endl;
	return 0;
}
