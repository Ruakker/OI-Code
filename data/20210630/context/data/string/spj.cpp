#include<bits/stdc++.h>
#include"testlib.h"
#define L long long
using namespace std;
int t,n,m,p;
string s;
inline int ran()
{
    return (rand()<<15)+rand();
}
int main(int argc,char**argv)
{
    registerTestlibCmd(argc,argv);
    //registerLemonChecker(argc,argv);
    int i,j,k;
	t=inf.readInt();
	while(t--)
	  {
	   n=inf.readInt();
	   m=ans.readInt();
       s=ouf.readString();
       if(s.size()!=m)
         p=1;
       for(i=0,j=0,k=0;i<s.size();i++)
         if(!i || s[i]==s[i-1])
           j++;
         else
           k+=(s.size()-i)*j,j=1;
       if(k!=n)
         p=2;
      }
    if(p==0)
      quitp(1.0,"Accepted");
    else if(p==1)
      quitp(0.0,"Wrong Length");
    else
 	  quitp(0.0,"Wrong Answer");
	return 0;
}

