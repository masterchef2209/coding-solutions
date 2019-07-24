		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

ll sieve[1505];

vector<ll>primes;

void precompute()
{
	for(ll i=2;i*i<=1504;i++)
	{
		if(sieve[i]==0)
		{
			for(ll j=2*i;j<=1504;j+=i)
			{
				sieve[j]=1;
			}
		}
	}
	for(ll i=2;i<=1504;i++)
	{
		if(sieve[i]==0)
		{
			primes.eb(i);
		}
	}
}

vector< pair<ll,ll> >edges;

ll visited[1500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	precompute();
	ll n;
	cin>>n;
	ll val=*lower_bound(primes.begin(),primes.end(),n);
	if((val-n)>(n/2))
	{
	    cout<<-1;
	}
	else
	{
	    for(ll i=1;i<n;i++)
	    {
	        edges.eb(i,i+1);
	    }
	    edges.eb(n,1);
	    ll tem=(val-n);
	    ll e=1;
	    while(tem>0)
	    {
	        if(visited[e])
	        {
	            e++;
	            continue;
	        }
	        if(e>n)
	            break;
	        ll e1=e+2;
	        if(e1>n)
	            e1-=n;
	        edges.eb(e,e1);
	        tem--;
	        visited[e]=1;
	        visited[e1]=1;
	        e++;
	    }
	    cout<<edges.size()<<"\n";
	    for(auto &x:edges)
	    {
	        cout<<x.fi<<" "<<x.se<<"\n";
	    }
	}
    return 0;
}


//252908XL