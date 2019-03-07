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
	ll n;
	cin>>n;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	vector<ll>::iterator it,it1;
	ll ans=-1;
	for(it=arr.begin();it!=arr.end();it++)
	{
		it1=upper_bound(arr.begin(),arr.end(),(*it)+5);
		ans=max(ans,(ll)(it1-it));
	}
	cout<<ans<<endl;
    return 0;
}