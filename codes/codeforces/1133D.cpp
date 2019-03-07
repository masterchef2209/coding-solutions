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

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>a(n),b(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll j=0;j<n;j++)
	{
		cin>>b[j];
	}
	map< pair<ll,ll> ,ll >mm;
	ll ans=0,zero=0,bothzero=0;
	for(ll i=0;i<n;i++)
	{
	    if(a[i]==0 && b[i]==0)
	    {
	        bothzero++;
	        continue;
	    }
	    if(b[i]==0)
	    {
	        zero++;
	        continue;
	    }
	    if(a[i]==0)
	        continue;
		ll gg=gcd(a[i],b[i]);
		ll num=b[i]/gg;
		ll den=a[i]/gg;
		pair<ll,ll> temp=mp(-num,den);
		mm[temp]++;
	}
	for(auto&x:mm)
	{
		if(x.second >ans)
		{
			ans=(x.second);
		}
	}
	cout<<max(zero,ans)+bothzero<<endl;
    return 0;
}