		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

#define SSIZE 200005

ll n,m,k;
vector< vector<ll> >adj(SSIZE);
vector<ll>path;
ll visited[SSIZE];
vector< set<ll> >nxt(SSIZE);
ll dist[SSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll u=0;u<m;u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[b].eb(a);
	}
	cin>>k;
	for(ll i=0;i<k;i++)
	{
		ll a;
		cin>>a;
		path.eb(a);
	}
	for(ll i=1;i<=n;i++)
	{
		dist[i]=LLONG_MAX;
	}
	ll st=path[k-1];
	queue< pair<ll,ll> >Q;
	visited[st]=1;
	Q.push(mp(st,0));
	dist[st]=0;
	while(!Q.empty())
	{
		pair<ll,ll> curr=Q.front();
		Q.pop();
		for(auto &nei:adj[curr.fi])
		{
			if(!visited[nei])
			{
				visited[nei]=1;
				dist[nei]=curr.se+1;
				Q.push(mp(nei,curr.se+1));
			}
			if((curr.se+1)==dist[nei])
			{
				nxt[nei].insert(curr.fi);
			}
		}
	}
	ll mmin=0,mmax=0;
	for(ll i=0;i<(k-1);i++)
	{
		ll node=path[i];
		ll nnode=path[i+1];
		if(nxt[node].find(nnode)==nxt[node].end())
			mmin++;
		if(nxt[node].size()==1 && (*nxt[node].begin())==nnode )
		{

		}
		else
		{
			mmax++;
		}
	}
	cout<<mmin<<" "<<mmax;
    return 0;
}


//252908XL