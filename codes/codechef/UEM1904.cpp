#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
//not accepted
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	string c,p;
	cin>>c>>p;
	set<char> haha,haha1;
	for(int i=0;i<(int)c.size();i++)
	{
		haha.insert(c[i]);
	}
	for(int j=0;j<(int)p.size();j++)
	{
		haha1.insert(p[j]);
	}
	int a=c.size(),b=haha.size();
	int c1=p.size(),d=haha1.size();
	int ans=abs(b-d);
	ans+=max(a,c1);
	cout<<ans<<endl;
    return 0;
}