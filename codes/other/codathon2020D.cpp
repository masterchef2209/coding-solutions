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

#define int long long
#define SSIZE 100005

ll n;

map< ll, vector< pair<ll,ll> > >mm;
set< pair<ll,ll> >ss;

ll parent[SSIZE];
ll size[SSIZE];

ll hehe=0;

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
    	hehe+=(size[a]*size[b]);
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<=n;i++)
	{
		make_set(i);
	}
	for(ll i=0;i<(n-1);i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		mm[w].eb(a,b);
	}
	for(auto &x:mm)
	{
		vector< pair<ll,ll> > &y=x.se;
		for(auto &z:y)
		{
			union_sets(z.fi,z.se);
		}
		ss.insert(mp(x.fi,hehe));
	}
// 	for(auto &deb:ss)
// 	{
// 	    cout<<deb.fi<<" "<<deb.se<<"\n";
// 	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		auto it=ss.upper_bound(mp(x,LLONG_MAX));
		if(it==ss.begin())
		{
			cout<<"0\n";
		}
		else
		{
			it--;
			cout<<( it->se )<<"\n";
		}
	}
    return 0;
}


//252908XL