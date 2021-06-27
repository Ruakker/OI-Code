#include<bits/stdc++.h>
using namespace std;
ifstream fin,fout,fstd;
ofstream fscore,freport;
int n,m,p,f[1000010];
inline int judge()
{
    int i,j,k;
    fin>>n;
    fstd>>m;
    for(i=1,k=0;i<=n;i++)
      {
       fout>>j;
       if(abs(j)!=1)
         return 0;
       k+=j;
       p=max(p,abs(k));
       f[i]=j;
      }
    for(i=1;i<=n;i++)
      for(j=1;i*j<=n;j++)
        if(f[i]*f[j]!=f[i*j])
          return 0;
    return int(100*sqrt(double(m)/p)+1e-6);
}
int main(int argc,char *argv[])
{
    fin.open(argv[1]);
    fout.open(argv[2]);
    fstd.open(argv[3]);
    fscore.open(argv[5]);
    freport.open(argv[6]);
    fscore<<judge()<<"\n";
    return 0;
}
