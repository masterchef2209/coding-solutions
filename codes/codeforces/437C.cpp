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
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	ll arr[n+10];
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		ans+=min(arr[a],arr[b]);
	}
	cout<<ans<<endl;
    return 0;
}