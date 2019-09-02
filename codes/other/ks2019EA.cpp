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

const int MAX = 100005;

vector< vector< pair<ll,ll> > >mst(MAX);
vector<ll> visited(MAX,0);

ll prims(ll i)
{
  priority_queue< pair<ll,ll>, vector< pair<ll,ll> > ,greater< pair<ll,ll>  >  > pq;
  ll minCost=0;
  pq.push(make_pair(0,i));
  while(!pq.empty())
  {
    pair< ll,ll > p=pq.top();
    pq.pop();
    ll x=p.second;
    if(visited[x])
      continue;
    visited[x]=1;
    minCost+=p.first;
    for(ll j=0;j<mst[x].size();j++)
    {
      if(!visited[mst[x][j].second])
      {
        pq.push(mst[x][j]);
      }
    }
  }
return minCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        cout<<"Case #"<<test<<": ";
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++)
        {
            mst[i].clear();
            visited[i]=0;
        }
        for(ll i=0;i<m;i++)
        {
            ll c,d;
            cin>>c>>d;
            mst[c].pb(mp(1,d));
            mst[d].pb(mp(1,c));
        }
        ll ans=0;
        ll cry=0;
        for(ll i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                ans+=prims(i);
                cry++;
            }
        }
        ans+=((cry-1)*2);
        cout<<ans;
        cout<<"\n";
    }
    return 0;
}


//252908XL