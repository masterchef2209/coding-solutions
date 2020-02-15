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

ll t;
vector< string >adj;
vector< ll >visited(1005,0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		adj.clear();
		for(ll i=0;i<1005;i++)
		{
			visited[i]=0;
		}
		ll n,k;
		cin>>n>>k;
		for(ll i=0;i<(n);i++)
		{
			string ss;
			cin>>ss;
			adj.eb(ss);
		}
		queue< pair<ll,ll> >Q;
		Q.push(mp(0,0));
		visited[0]=1;
		ll ans;
		while(!Q.empty())
		{
			ll curr=Q.front().fi;
			ll dist=Q.front().se;
			Q.pop();
			if(curr==(n-1))
			{
				ans=dist;
				break;
			}
			for(ll j=0;j<adj[curr].size();j++)
			{
			    ll frick=abs(curr-j);
				if(adj[curr][j]=='1' && visited[j]==0 && frick<=k)
				{
					visited[j]=1;
					Q.push(mp(j,dist+1));
				}
			}
		}
		if(visited[n-1])
		{
			cout<<ans<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
    return 0;
}


//252908XL