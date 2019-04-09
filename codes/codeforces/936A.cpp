#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

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
	ll k,d,t;
	cin>>k>>d>>t;
	if(t<=k)
	{
		cout<<fixed<<setprecision(10)<<t;
		return 0;
	}
	if(k>=d)
	{
		if(k%d==0)
		{
			cout<<t;
			return 0;
		}
		d=(k/d)*d+d;
	}
	ll on,off;
	on=k;
	off=d-k;
	ll num=(2*t)/(2*on+off);
	double rem=t-num*(on+off/2.0);
	if(rem<=k)
	{
		cout<<fixed<<setprecision(10)<<num*(on+off)+rem;
	}
	else
	{
		cout<<fixed<<setprecision(10)<<num*(on+off)+on+2*(rem-on);
	}
	return 0;
}