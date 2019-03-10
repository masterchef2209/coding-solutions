#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
//question removed
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

vector<vector<ll> >adj(100005);
vector<ll>val(100005);
vector< pair<ll,ll> >degree(100005);
vector<ll>visited(100005);
vector< vector< pair<ll,ll> > >components(100005);
ll ans=0;
ll n,m;

ll yo=0;

void findcc(ll i,ll p)
{
    visited[i]=1;
	for(auto &x:adj[i])
	{
		if(x==p)
			continue;
		if(visited[x]==1)
		{
			components[yo].eb(mp(i,x));
		}
		else if(visited[x]==0)
		{
			components[yo].eb(mp(i,x));
			findcc(x,i);
		}
	}
	visited[i]=2;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    for(ll i=0;i<=yo;i++)
	        components[i].clear();
		ans=0;yo=0;
		for(ll i=0;i<=n;i++)
		{
			adj[i].clear();
			degree[i]=mp(0,0);
			visited[i]=0;
		}
		for(ll i=0;i<m;i++)
		{
			ll a,b;
			cin>>a>>b;
			adj[a].eb(b);
			adj[b].eb(a);
			degree[a]=mp(degree[a].first+1,a);
			degree[b]=mp(degree[b].first+1,b);
		}
		for(ll i=1;i<=n;i++)
		{
			cin>>val[i];
		}
        for(ll i=1;i<=n;i++)
		{
			if(!visited[i])
			{
			    yo++;
				findcc(i,-1);
			}
		}
        vector<int>mark(n+1,0);
        for(ll i=1;i<=yo;i++)
        {
            multiset<ll>value;
            set< pair<ll,ll> >degree1;
            for(auto &y : components[i])
            {
                if(!mark[y.first])
                {
                    value.insert(val[y.first]);
                    mark[y.first]=1;
                }
                if(!mark[y.second])
                {
                    value.insert(val[y.second]);
                    mark[y.second]=1;
                }
                degree1.insert(degree[y.first]);
                degree1.insert(degree[y.second]);
            }
            map<ll,ll>weight;
            auto z1=value.begin();
            for(auto &z:degree1)
            {
                weight[z.second]= *z1;
                z1++;
            }
            for(auto &y:components[i])
            {
                ans+=max(weight[y.first],weight[y.second]);
            }
        }
        cout<<ans<<endl;
	}
    return 0;
}