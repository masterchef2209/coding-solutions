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
#define SSIZE 505

ll t;
ll n;

vector< pair<double,double> >points(SSIZE);
vector< vector< pair<long double,ll> > >mst(SSIZE);
vector<int>visited(SSIZE,0);

long double eudist(pair<double,double>&a,pair<double,double>&b)
{
    long double delx=abs(a.fi-b.fi);
    long double dely=abs(a.se-b.se);
    return sqrt(delx*delx+dely*dely);
}

long double prims(ll i)
{
  priority_queue< pair<long double,ll>, vector< pair<long double,ll> > ,greater< pair<long double,ll>  >  > pq;
  long double minCost=0;
  pq.push(make_pair(0.0,i));
  while(!pq.empty())
  {
    pair< long double,int > p=pq.top();
    pq.pop();
    ll x=p.second;
    if(visited[x])
      continue;
    visited[x]=1;
   // cout<<p.se<<" "<<p.fi<<endl;
    minCost+=p.first;
    for(int j=0;j<mst[x].size();j++)
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
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(ll i=0;i<=n;i++)
	    {
	        visited[i]=0;
	        mst[i].clear();
	    }
	    for(ll i=0;i<n;i++)
	    {
	        cin>>points[i].fi>>points[i].se;
	    }
	    for(ll i=0;i<n;i++)
	    {
	        for(ll j=i+1;j<n;j++)
	        {
	            long double mht=abs(points[i].fi-points[j].fi)+abs(points[i].se-points[j].se);
	            if(mht==1.0)
	            {
	                mst[i].eb(mp(0.0,j));
	                mst[j].eb(mp(0.0,i));
	            }
	            else
	            {
	                long double weight=eudist(points[i],points[j]);
	               // cout<<i<<" "<<j<<endl;
	               // cout<<weight<<endl;
	                mst[i].eb(mp(weight,j));
	                mst[j].eb(mp(weight,i));
	            }
	        }
	    }
	    long double mincost=prims(0);
	    cout<<fixed<<setprecision(6);
	    cout<<mincost<<"\n";
	}
    return 0;
}


//252908XL