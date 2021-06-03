// /*
// 	Author: Chocola4ever
// 	Date: 2021-04-27 08:52:40
// 	LastEditTime: 2021-04-27 16:56:41
// 	FilePath: \Programs\20210427\expand.cpp
// 	Description: RP++
// */
// #include<bits/stdc++.h>
// #define ll long long
// #define inf 0x3f3f3f3f
// using namespace std;
// ll read(){
// 	ll x=0,w=1;
// 	char ch=getchar();
// 	for (;!isdigit(ch);ch=getchar())
// 		if (ch=='-') w=-1;
// 	for (;isdigit(ch);ch=getchar())
// 		x=x*10+(ch-'0');
// 	return x*w;
// }
// const int N=305,dire[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
// struct Chocola{
// 	int sz,val;
// }a[N][N];
// struct Forever{
// 	int x,y;
// }ed[N];
// struct Best{
// 	int val,dis;
// }dp[1<<15][N];
// int n,m,s,x,y,p,stx,sty,S,mx,mn;
// int Val[N][N],Dis[N][N],sum[N][N],val[N][N][20],dis[N][N][20],inq[N][N][20];
// queue<Forever> q;
// void bfs(int x0,int y0,int k){
// 	q.push((Forever){x0,y0});
// 	inq[x0][y0][k]=1;
// 	dis[x0][y0][k]=0;
// 	val[x0][y0][k]=0;
// 	while (!q.empty()){
// 		Forever temp=q.front();
// 		q.pop();
// 		int x=temp.x,y=temp.y;
// 		inq[x][y][k]=0;
// 		for (int i=0;i<4;++i){
// 			int nowx=x+dire[i][0],nowy=y+dire[i][1];
// 			if (!a[nowx][nowy].val){
// 				if (!inq[nowx][nowy][k]&&!a[nowx][nowy].val){
// 					dis[nowx][nowy][k]=dis[x][y][k]+1;
// 					val[nowx][nowy][k]=val[x][y][k]+a[nowx][nowy].sz;
// 					q.push((Forever){nowx,nowy});
// 					inq[nowx][nowy][k]=1;
// 				}else if (dis[nowx][nowy][k]==dis[x][y][k]+1&&val[nowx][nowy][k]<val[x][y][k]+a[nowx][nowy].sz)
// 					val[nowx][nowy][k]=val[x][y][k]+a[nowx][nowy].sz,
// 					q.push((Forever){nowx,nowy});
// 			}
// 		}
// 	}
// 	for (int i=1;i<=p;++i)
// 		Val[i][k]=val[ed[i].x][ed[i].y][k],
// 		Dis[i][k]=dis[ed[i].x][ed[i].y][k];
// }
// void init(){
// 	for (int i=1;i<=n;++i)
// 		for (int j=1;j<=m;++j)
// 			sum[i][j]=a[i][j].val+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
// 	for (int i=1;i<=n;++i)
// 		for (int j=1;j<=n;++j){
// 			if (a[i][j].val==1) continue;
// 			int mn=min(min(min(i-1,j-1),min(n-i,m-j)),mx);
// 			for (int k=mn;k>=0;k--)
// 				if (sum[i+k][j+k]+sum[i+k][j-k]+sum[i-k][j+k]-sum[i-k][j-k]==0){
// 					a[i][j].sz=k;
// 					break;
// 				}
// 		}
// 	for (int i=0;i<=n;++i)
// 		a[i][0].val=a[i][m+1].val=1;
// 	for (int i=0;i<=m;++i)
// 		a[0][i].val=a[n+1][i].val=1;
// }
// int main(){
// 	// freopen("expand.in","r",stdin);
// 	// freopen("expand.out","w",stdout);
// 	n=read(),m=read(),s=read();
// 	init();
// 	for (int i=1;i<=n;++i)
// 		for (int j=1;j<=m;++j)
// 			a[i][j].val=read();
// 	stx=read()+1,sty=read()+1,p=read(),S=1<<p;
// 	for (int i=1;i<=p;++i)
// 		ed[i]=Forever{read(),read()};
// 	for (int i=0;i<=p;++i)
// 		bfs(ed[i].x,ed[i].y,i);
// 	for (int i=0;i<1<<15;++i)
// 		for (int j=0;j<N;++j)
// 			dp[i][j].dis=inf;
// 	for (int i=0;i<p;++i)
// 		dp[1<<i][i].val=Val[0][i+1],dp[1<<i][i].dis=Dis[0][i+1];
// 	for (int s=0;s<p;++s)
// 		for(int i=0;i<p;i++)
// 			if(s>>i&1){
// 				if(dp[s][i].dis==inf) continue;
// 				for(int j=0;j<p;j++) if(!(s>>j&1)){
// 					if(dp[s][i].dis+Dis[i+1][j+1]<dp[s|(1<<j)][j].dis)
// 						dp[s|(1<<j)][j].dis=dp[s][i].dis+Dis[i+1][j+1],
// 						dp[s|(1<<j)][j].val=dp[s][i].val+Val[i+1][j+1];
// 					else if(dp[s][i].dis+Dis[i+1][j+1]==dp[s|(1<<j)][j].dis)
// 						dp[s|(1<<j)][j].val=max(dp[s|(1<<j)][j].val,dp[s][i].val+Val[i+1][j+1]);
// 				}
// 			}
// 	int mndis=inf,mxval=0;
// 	for(int i=0;i<p;i++){
// 		if(dp[S-1][i].dis<mndis) mndis=dp[S-1][i].dis,mxval=dp[S-1][i].val;
// 		else if(dp[S-1][i].dis==mndis) mxval=max(mxval,dp[S-1][i].val);
// 	}
// 	printf("%d %d\n",mndis,mxval+a[stx][sty].val);
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
const int N=305,K=15;
const int inf_int=1061109567;
const int dx[5]={0,1,-1,0,0};
const int dy[5]={0,0,0,1,-1};

struct Position{
	int x,y;
}pos[N];

struct Node{
	int x,y,cnt,sum;
};

int n,m,k,Maxsiz,Sx,Sy;
int siz[N][N],dis[K+1][N][N],Siz[K+1][N][N];
int Map[N][N],Mp[N][N],sum[N][N];
int f[(1<<K)+1][K+1],g[(1<<K)+1][K+1];
bool vis[N][N][5];
// int Upd[K+1][N][N];
// int popcnt[(1<<K)+1];
queue <Node> Q;

inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)) { if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

inline int Getmax(int x,int y){ return (x>y) ? x : y; }
const int inf=0x3f3f3f3f;
inline void Bfs(int id,int Stx,int Sty){

	memset(vis,0,sizeof(vis));
	memset(dis[id],0x3f,sizeof(dis[id]));
	memset(Siz[id],0,sizeof(Siz[id]));
	while (!Q.empty()) Q.pop();
	Q.push((Node){Stx,Sty,0});
	dis[id][Stx][Sty]=0;
	Siz[id][Stx][Sty]=0;
	while (!Q.empty()){
		Node Front=Q.front(); Q.pop();
		int x=Front.x,y=Front.y;
		for (int i=1;i<=4;++i){
			int tx=Front.x+dx[i],ty=Front.y+dy[i];
			int step=dis[id][x][y]+1,SumNow=Siz[id][x][y]+siz[tx][ty];

			if (tx<1 || ty<1 || tx>n || ty>m) continue;
			if (Map[tx][ty]==1) continue;
			if (dis[id][tx][ty]<step) continue;
			if ((dis[id][tx][ty]==step ) && (Siz[id][tx][ty]>=SumNow)) continue;
			if (vis[tx][ty][i]==1) continue;

			vis[tx][ty][i]=1;
			dis[id][tx][ty]=step;
			Siz[id][tx][ty]=SumNow;
			Q.push((Node){tx,ty,step,SumNow});
		}
	}
}

inline void Prepare(){
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			sum[i][j]=Map[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			siz[i][j]=0;
			for (int r=1;r<=Maxsiz;++r){
				if (i-r<1 || j-r<1 || i+r>n || j+r>m) break;
				int Sum=sum[i+r][j+r]-sum[i+r][j-r-1]-sum[i-r-1][j+r]+sum[i-r-1][j-r-1];
				if (Sum>0) break;
				siz[i][j]=r;
			}
		}
}

inline void DynamicProgramming(){
	// popcnt[0]=0;
	// for (int i=1;i<=(1<<k);++i) popcnt[i]=popcnt[i>>1]+(i&1);
	// for (int i=0;i<=10;++i)
	// 	printf("popcnt[%d]=%d\n",i,popcnt[i]);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0,g[0][0]=siz[Sx][Sy];
	for (int S=0;S<(1<<k);++S){
		for (int j=0;j<=k;++j){
			if (!((S>>(j-1))&1)&&j) continue;
//			if(f[S][j]==inf) continue;
			for (int i=1;i<=k;++i){
				if ((S>>(i-1))&1) continue;
				if (f[S|(1<<(i-1))][i]>f[S][j]+dis[j][pos[i].x][pos[i].y]){
					f[S|(1<<(i-1))][i]=f[S][j]+dis[j][pos[i].x][pos[i].y];
					g[S|(1<<(i-1))][i]=g[S][j]+Siz[j][pos[i].x][pos[i].y];
				}
//				else if (f[S|(1<<(i-1))][i]==f[S][j]+dis[j][pos[i].x][pos[i].y])
//					g[S|(1<<(i-1))][i]=Getmax(g[S|(1<<(i-1))][i],g[S][j]+Siz[j][pos[i].x][pos[i].y]);
			}
		}
	}
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	n=read(),m=read(),Maxsiz=read();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			Map[i][j]=read();
			sum[i][j]=Map[i][j];
		}
	Sx=read()+1,Sy=read()+1,k=read();
	Prepare();
	for (int i=1;i<=k;++i){
		pos[i].x=read()+1,pos[i].y=read()+1;
		Map[pos[i].x][pos[i].y]=2;
	}
	pos[0]=(Position){Sx,Sy};
	for (int i=0;i<=k;++i) Bfs(i,pos[i].x,pos[i].y);
	DynamicProgramming();
	int ans1=inf,ans2=0;
	for (int i=1;i<=k;++i)
		if (f[(1<<k)-1][i]<ans1) ans1=f[(1<<k)-1][i],ans2=g[(1<<k)-1][i];
		else if (f[(1<<k)-1][i]==ans1) ans2=Getmax(ans2,g[(1<<k)-1][i]);
	printf("%d %d\n",ans1,ans2);
	return 0;
}