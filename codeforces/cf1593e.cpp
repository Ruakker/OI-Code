#include<bits/stdc++.h>
using namespace std;
const int N=114514*7;
const int inf=1919810;

struct Edge{
	int vet,nxt;
}e[N<<1];

int n,k,edge=0,head[N];
int deg[N],dep[N],Rkkr[N],rkk[N];
bool inq[N];
deque <int> Q;

#define Rk push_back

vector <int> G[N];

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int rkkkr; cin>>rkkkr;
	for (int LL=1;LL<=rkkkr;++LL){
        cin>>n>>k;
		if (n==1){
			if (k>=1) cout<<"0"<<endl;
			else cout<<"1"<<endl;
			continue;
		}
        for (int i=1;i<=n;++i) G[i].clear();
        for (int i=1;i<=n;++i) rkk[i]=0;
		for (int i=1;i<=n-1;++i){
            int x,y; cin>>x>>y;
            G[x].Rk(y); G[y].Rk(x);
			++deg[x],++deg[y];
            ++rkk[x];
		}
        for (int i=1;i<=n;++i)
            if (i%10000==0) cerr<<"good"<<endl;
		while (!Q.empty()) Q.pop_front();
		for (int i=1;i<=n;++i) dep[i]=inf,inq[i]=false;
		for (int i=1;i<=n;++i)
			if (deg[i]==1){ Q.push_front(i); inq[i]=true; dep[i]=1; }
		while (!Q.empty()){
			int x=Q.front(); Q.pop_front();
            // cout<<"x="<<x<<endl;
			for (auto v : G[x]){
		        // printf("dep: "); for (int i=1;i<=n;++i) printf("%lld ",dep[i]); printf("\n");
                deg[v]=deg[v]-1;
				if (deg[v]<=1){
					if (!inq[v]){
						inq[v]=true;
						dep[v]=dep[x]+1;
						Q.push_back(v);
					}
				}
			}
            // printf("x=%lld dep[x]=%lld\n",x,dep[x]);
			// printf("x=%lld v=%lld deg[v]=%lld\n",x,v,deg[v]-1);
            if (rkk[x]>n*2){ cerr<<"EEEEEEEEEERRRRRRRRRRRRRROOOOOOOOORRR"<<endl; return 0; }
		}
        //  // // // cout<<"dep: "; for (int i=1;i<=n;++i) cout<<dep[i]<<" "; cout<<endl;
		int qty_is_my_dd=0;
		for (int i=1;i<=n;++i)
			if (dep[i]>k) ++qty_is_my_dd;
        cerr<<qty_is_my_dd<<endl;
        cout<<qty_is_my_dd<<endl;
	}
	return 0;
}
