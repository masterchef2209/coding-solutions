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
	if(m%n!=0)
	{
	    cout<<-1<<endl;
	    return 0;
	}
	ll x=m/n;
	vector<ll>temp;
	ll ans=0;
	for(int i=2;i<=3;i++)
	{
		if(x%i==0)
		{
			while(x%i==0)
			{
				ans++;
				x/=i;
			}
		}
	}
	if(x!=1)
	{
		cout<<-1<<endl;
	}
	else
	{
		if(n==m)
		{
			cout<<0<<endl;
		}
		else
			cout<<ans<<endl;
	}
    return 0;
}