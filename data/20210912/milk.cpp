#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
struct node{
	int r,c;ll t;
	bool operator <(const node &b)const{
		if(r==b.r)return c<b.c;
		else return r<b.r;
	}
}a[10005];
ll f[10005],ans[10005];
ll lll[10005],rr[10005],lb[10005],rb[10005],g[10005],gb[10005];
vector<pair<ll,int> > v;
int nxt[10005];
void dp(int l,int r){
	memset(lll,0x3f,sizeof(lll));
	memset(rr,0x3f,sizeof(rr));
	memset(lb,0x3f,sizeof(lb));
	memset(rb,0x3f,sizeof(rb));
	memset(g,0x3f,sizeof(g));
	memset(gb,0x3f,sizeof(gb));
	if(a[l].r==0){
		v.clear();
		v.push_back(make_pair(0,0));
		for(int i=l;i<=r;i++)v.push_back(make_pair(a[i].t,i));
		for(int i=0;i<v.size();i++)nxt[i]=i+1;
		sort(v.begin(),v.end());
		rr[0]=0;
		if(a[l].c>0)rb[0]=0;
		else rb[0]=0x3f3f3f3f3f3f3f3fll;
		for(int i=r;i>=r-v.size()+2;i--){
			int now=1;
			ll s=0;
			int id=0;
			for(int j=nxt[0];j<v.size();j=nxt[j]){
				s+=v[j].first;
				rr[now]=min(rr[now],s+a[i].c+(m-1)/2);
				rb[now]=min(rb[now],s+max(a[i].c,0)*2+(m-1)/2);
				if(nxt[j]<v.size()&&v[nxt[j]].second==i)id=j;
				now++;
			}
			nxt[id]=nxt[nxt[id]];
		}
		for(int i=0;i<=r-l+1;i++)g[i]=rr[i],gb[i]=rb[i];
	}else{
		int cnt=0;
		for(int i=l;i<=r;i++)if(a[i].c<0)cnt++;
		v.clear();
		v.push_back(make_pair(0,0));
		for(int i=l;i<=r;i++)if(a[i].c<0)v.push_back(make_pair(a[i].t,i));
		for(int i=0;i<v.size();i++)nxt[i]=i+1;
		sort(v.begin(),v.end());
		lll[0]=lb[0]=0;
		for(int i=l;i<=l+v.size()-2;i++){
			int now=1;
			ll s=0;
			int id=0;
			for(int j=nxt[0];j<v.size();j=nxt[j]){
				s+=v[j].first;
				lll[now]=min(lll[now],s+abs(a[i].c));
				lb[now]=min(lb[now],s+abs(a[i].c)*2);
				if(nxt[j]<v.size()&&v[nxt[j]].second==i)id=j;
				now++;
			}
			nxt[id]=nxt[nxt[id]];
		}
		v.clear();
		v.push_back(make_pair(0,0));
		for(int i=l;i<=r;i++)if(a[i].c>0)v.push_back(make_pair(a[i].t,i));
		for(int i=0;i<v.size();i++)nxt[i]=i+1;
		sort(v.begin(),v.end());
		rr[0]=rb[0]=0;
		for(int i=r;i>=r-v.size()+2;i--){
			int now=1;
			ll s=0;
			int id=0;
			for(int j=nxt[0];j<v.size();j=nxt[j]){
				s+=v[j].first;
				rr[now]=min(rr[now],s+abs(a[i].c));
				rb[now]=min(rb[now],s+abs(a[i].c)*2);
				if(nxt[j]<v.size()&&v[nxt[j]].second==i)id=j;
				now++;
			}
			nxt[id]=nxt[nxt[id]];
		}
		for(int i=0;i<=cnt;i++)
			for(int j=0;j<=r-l+1-cnt;j++){
				g[i+j]=min(g[i+j],min(lll[i]+rb[j],lb[i]+rr[j]));
				gb[i+j]=min(gb[i+j],lb[i]+rb[j]);
			}
	}
//	printf("l=%d r=%d\n",l,r);
//	printf("l:");for(int i=0;i<=k;i++)printf("%lld ",lll[i]);puts("");
//	printf("lb:");for(int i=0;i<=k;i++)printf("%lld ",lb[i]);puts("");
//	printf("r:");for(int i=0;i<=k;i++)printf("%lld ",rr[i]);puts("");
//	printf("rb:");for(int i=0;i<=k;i++)printf("%lld ",rb[i]);puts("");
//	printf("g:");for(int i=0;i<=k;i++)printf("%lld ",g[i]);puts("");
//	printf("gb:");for(int i=0;i<=k;i++)printf("%lld ",gb[i]);puts("");
	for(int i=0;i<=k;i++)f[i]=min(0x3f3f3f3f3f3f3f3fll,f[i]+a[l].r-a[l-1].r);
	for(int i=k;i>=0;i--){
		for(int j=0;j<=min(i,r-l+1);j++){
			f[i]=min(f[i],f[i-j]+gb[j]);
			ans[i]=min(ans[i],f[i-j]+g[j]);
		}
	}
	if(a[l].r==0)f[0]=(m-1)/2;
//	for(int i=0;i<=k;i++)printf("%lld ",f[i]);puts("");
}
int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d%lld",&x,&y,&a[i].t);
		a[i].r=x-1,a[i].c=y-(m+1)/2; 
	}
	sort(a+1,a+k+1);
	memset(f,0x3f,sizeof(f));
	memset(ans,0x3f,sizeof(ans));
	if(a[1].r==0)f[0]=0;
	else f[0]=(m-1)/2;
	int lst=1;
	for(int i=2;i<=k;i++)
		if(a[i].r>a[i-1].r){
			dp(lst,i-1);
			lst=i;
		}
	dp(lst,k);
	for(int i=1;i<=k;i++)printf("%lld ",ans[i]);puts("");
	return 0;
}