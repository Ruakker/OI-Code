#include <bits/stdc++.h>
#define N 410000
using namespace std;
typedef long long ll;
const int inf=1e9;
int n,m,s,t,mx,num=-1,d,a,b;
int f[N],nxt[N],data[N],fl[N],co[N],dis[N],vis[N],lst[N],coo[N];
void add(int x,int y,int w,int c){
//	cout<<x<<" "<<y<<endl;
	nxt[++num]=f[x]; f[x]=num; data[num]=y; fl[num]=w; co[num]=c;
	nxt[++num]=f[y]; f[y]=num; data[num]=x; fl[num]=0; co[num]=-c;
}
queue<int> q;
bool spfa(){
	int x,y;
	for(int i=1;i<=t;i++)dis[i]=inf,vis[i]=0;
	dis[s]=0; q.push(s); vis[s]=1;
	while(!q.empty()){
		x=q.front(); q.pop(); 
		for(int i=f[x];i!=-1;i=nxt[i]){
			y=data[i]; 
			if(fl[i]==0)continue;
			if(dis[y]>dis[x]+co[i]){
				coo[y]=i; lst[y]=x; dis[y]=dis[x]+co[i]; 
				if(!vis[y]){ q.push(y); }
			}
		}
	}
	return dis[t]!=inf;
}
void dinic_Maxflow_Mincost(){
	int ans=0,x,flow,sum=0;
	while(spfa()){
		x=t; flow=inf;
		while(x!=s){
			flow=min(fl[coo[x]],flow); 
			x=lst[x];
		} 
		sum+=flow;
		ans+=dis[t]*flow;
		x=t;
		while(x!=s){ fl[coo[x]]-=flow; fl[coo[x]^1]+=flow; x=lst[x]; }
	}
	cout<<ans<<endl;
}
int id[N],pos[N];
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	memset(f,-1,sizeof(f));
	cin>>n>>d>>a>>b; d<<=1;
	if(n<=20){
		for(int i=0;i<n;i++) cin>>id[i];
		int ans=1e9,now;
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++) pos[j]=id[j]+d*((i>>j)&1);
			sort(pos,pos+n);
			now=a;
			for(int j=1;j<n;j++) now+=min((pos[j]-pos[j-1])*b,a);
			ans=min(ans,now);
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<n*a<<endl;
}
