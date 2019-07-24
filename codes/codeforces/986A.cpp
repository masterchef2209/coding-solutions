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

#define INF INT_MAX

ll n,m,k,s;
#define SIZE 100005
vector< vector<ll> >adj(SIZE);
vector< vector<ll> >type(110);
ll ans[SIZE][110];
ll dist[SIZE];
ll visited[SIZE];

int main()
{
	scanf("%lld %lld %lld %lld",&n,&m,&k,&s);
	for(ll i=1;i<=n;i++)
	{
		ll ty;
		scanf("%lld",&ty);
		type[ty].eb(i);
	}
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		scanf("%lld %lld",&a,&b);
		adj[a].eb(b);
		adj[b].eb(a);
	}
	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			dist[j]=INF;
			visited[j]=0;
		}
		queue<ll>Q;
		for(ll j=0;j<type[i].size();j++)
		{
			Q.push(type[i][j]);
			dist[type[i][j]]=0;
			visited[type[i][j]]=1;
		}
		while(!Q.empty())
		{
			ll curr=Q.front();
			Q.pop();
			for(auto &nei:adj[curr])
			{
				if(!visited[nei] && (dist[nei]>(dist[curr]+1)) )
				{
					visited[nei]=1;
					dist[nei]=dist[curr]+1;
					Q.push(nei);
				}
			}
		}
		for(ll p=1;p<=n;p++)
		{
			ans[p][i]=dist[p];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		nth_element(ans[i]+1,ans[i]+s,ans[i]+k+1);
		ll hehe=0;
		for(ll j=1;j<=s;j++)
		{
			hehe+=ans[i][j];
		}
		cout<<hehe<<" ";
	}
    return 0;
}


//252908XL