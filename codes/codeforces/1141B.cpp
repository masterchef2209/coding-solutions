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
	vector<int>temp;
	for(ll i=0;i<n;i++)
	{
		int hey;
		cin>>hey;
		temp.eb(hey);
	}
	ll ans=-1,count=0;
	for(int j=0;j<2*n;j++)
	{
		if(temp[(j%n)]==1)
		{
			count++;
		}
		else
		{
			ans=max(count,ans);
			count=0;
		}
	}
	ans=max(count,ans);
	cout<<ans<<endl;
    return 0;
}