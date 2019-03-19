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
	vector<ll>arr(n),ans(n);
	ans[0]=0;
	arr[0]=0;
	ll temp=0;
	for(ll i=1;i<n;i++)
	{
		    cin>>arr[i];
			ans[i]=ans[i-1]+arr[i];
			temp=min(ans[i],temp);
	}
	ll ai=1-temp;
	set<ll>yo;
	vector<ll>yo1;
	for(ll i=0;i<n;i++)
	{
	    yo1.eb(ai+ans[i]);
		yo.insert(ai+ans[i]);
	}
	if( ((*yo.begin())!=1) || (*prev(yo.end())!=n) || (yo.size()!=n) )
	{
		cout<<-1<<endl;
		return 0;
	}
	for(auto &x: yo1)
	{
		cout<<x<<" ";
	}
	cout<<endl;
    return 0;
}