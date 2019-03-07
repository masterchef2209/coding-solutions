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

ll prefixxor(ll k)
{
	switch(k%4)
	{
		case 0:return k;
		case 1:return 1;
		case 2:return k+1;
		case 3:return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	ll p=0;
	for(ll i=0;i<n;i++)
	{
		ll temp;
		cin>>temp;
		p^=temp;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans^=(((n/i)%2)*prefixxor(i-1))^(prefixxor(n%i));
	}
	ans^=p;
	cout<<ans<<endl;
    return 0;
}