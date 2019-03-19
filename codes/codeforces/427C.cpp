#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
#define INF LLONG_MAX
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

ll yo=0;

vector< vector<ll> >adj(300005);
vector<ll>cost(300005);
vector<ll>id(300005,-1);
vector<ll>low(300005,-1);
vector< vector<ll> >components(300005);
vector<ll>mincost(300005);

stack<ll>st;
vector<ll>onst(300005,-1);

ll timer=0;

void dfs(ll i)
{
	st.push(i);
	onst[i]=1;
	id[i]=low[i]=timer++;
	for(auto &x:adj[i])
	{
		if(id[x]==-1)
			dfs(x);
		if(onst[x]==1)
			low[i]=min(low[i],low[x]);
	}
	if(id[i]==low[i])
	{
		yo++;
		ll temp=INF;
		while(!st.empty())
		{
			ll a=st.top();
			st.pop();
			low[a]=id[i];
			temp=min(temp,cost[a]);
			onst[a]=-1;
			components[yo].eb(a);
			//cout<<a<<endl;
			if(a==i) break;
		}
		mincost[yo]=temp;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>cost[i];
	}
	ll m;
	cin>>m;
	for(ll j=0;j<m;j++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
	}
	for(ll i=1;i<=n;i++)
	{
		if(id[i]==-1)
		{
			dfs(i);
		}
	}
	unsigned long long ans1=0,ans2=1;
	//cout<<yo<<endl;
	for(ll i=1;i<=yo;i++)
	{
	    //cout<<mincost[i]<<" ";
		ans1+=mincost[i];
		ll temp1=0;
		for(auto &x:components[i])
		{
		    //cout<<x<<" ";
			if(cost[x]==mincost[i])
			{
				temp1++;
			}
		}
		ans2=((ans2%mod)*(temp1%mod))%mod;
	}
//	cout<<endl;
	cout<<ans1<<" "<<ans2<<endl;
    return 0;
}