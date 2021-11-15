#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
ll LIM=1.1e18;
ll target;
ll safemul(ll a,ll b) {
	if((double)a*b>4e18) throw "overflow";
	ll c=a*b; if(c>LIM) throw "overflow";
	return c;
}
ll safeadd(ll a,ll b) {
	ll c=a+b; if(c>LIM) throw "overflow";
	return c;
}
ll safeeval(string s) {
	int n=s.size();
	vector<ll> vals;
	vector<char> ops;
	int typ=0;
	for(int i=0;i<n;++i) {
		if(isdigit(s[i])) {
			if(typ!=0) throw "expecting op";
			ll x=s[i]-48;
			while(i+1<n&&isdigit(s[i+1]))
				x=safeadd(safemul(x,10),s[++i]-48);
			vals.pb(x);
			typ^=1;
		}
		else if(s[i]=='(') {
			if(typ!=0) throw "excepting op";
			ops.pb('(');
		}
		else if(s[i]==')') {
			if(typ!=1) throw "excepting num";
			while(ops.size()&&ops.back()!='(') {
				char o=ops.back(); ops.pop_back();
				if(vals.size()<2) throw "no sufficient operands";
				ll v1=vals.back(); vals.pop_back();
				ll v2=vals.back(); vals.pop_back();
				vals.pb((o=='+')?safeadd(v1,v2):safemul(v1,v2));
			}
			if(!ops.size()) throw "parenthesis not matching";
			ops.pop_back();
		}
		else if(s[i]=='+') {
			if(typ!=1) throw "excepting num"; typ^=1;
			while(ops.size()&&ops.back()!='(') {
				char o=ops.back(); ops.pop_back();
				if(vals.size()<2) throw "no sufficient operands";
				ll v1=vals.back(); vals.pop_back();
				ll v2=vals.back(); vals.pop_back();
				vals.pb((o=='+')?safeadd(v1,v2):safemul(v1,v2));
			}
			ops.push_back('+');
		}
		else if(s[i]=='*') {
			if(typ!=1) throw "excepting num"; typ^=1;
			while(ops.size()&&ops.back()!='('&&ops.back()!='+') {
				char o=ops.back(); ops.pop_back();
				if(vals.size()<2) throw "no sufficient operands";
				ll v1=vals.back(); vals.pop_back();
				ll v2=vals.back(); vals.pop_back();
				vals.pb((o=='+')?safeadd(v1,v2):safemul(v1,v2));
			}
			ops.push_back('*');
		}
		else throw "invalid char";
	}
	if(typ!=1) throw "excepting num";
	while(ops.size()&&ops.back()!='(') {
		char o=ops.back(); ops.pop_back();
		if(vals.size()<2) throw "no sufficient operands";
		ll v1=vals.back(); vals.pop_back();
		ll v2=vals.back(); vals.pop_back();
		vals.pb((o=='+')?safeadd(v1,v2):safemul(v1,v2));
	}
	if(ops.size()||vals.size()!=1) throw "invalid end state";
	return vals.back();
}
ll eval(string s) {
	ll val;
	try {
		val=safeeval(s);
	}
	catch(...) {
		return -1;
	}
	return val;
}
template<class T>
int go(T& s) {
	string w=s.readToken(),g;
	if(w.size()>500) s.quitf(_wa,"too long");
	for(auto c:w) {
		if(c!='+'&&c!='*'&&c!='1'&&c!='4'&&c!='5'&&c!='('&&c!=')')
			s.quitf(_wa,"invalid character");
		if(isdigit(c)) g.pb(c);
	}
	if(g.size()%6) s.quitf(_wa,"not [114514]+");
	for(int i=0;i<(int)g.size();++i)
		if(g[i]!="114514"[i%6]) s.quitf(_wa,"not [114514]+");
	if(eval(w)!=target) s.quitf(_wa,"not equal to target");
	return w.size();
}
int main(int argc,char* argv[]) {
	registerTestlibCmd(argc,argv);
//	registerLemonChecker(argc,argv);
	int T=inf.readInt(),ml=0;
	for(int ts=1;ts<=T;++ts) {
		target=inf.readLong();
		go(ans);ml=max(ml,go(ouf));
	}
	while(!ouf.seekEof()) ouf.readToken();
	quitf(_ok,"good job  maxlen=%d",ml);
}
