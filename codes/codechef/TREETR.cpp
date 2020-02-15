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

#define SSIZE 100005

vector< vector<ll> >adj(SSIZE);
vector<ll>weight(SSIZE);
vector<ll>visited(SSIZE);

ll subsize[SSIZE];
ll value[SSIZE];
ll t[4*SSIZE];
ll timedata[SSIZE];
ll tim=0;

void dfs(ll curr)
{
    visited[curr]=1;
    value[tim]=weight[curr];
    timedata[curr]=tim;
    ll tim1=tim;
    tim++;
    for(auto &nei:adj[curr])
    {
        if(!visited[nei])
        {
            dfs(nei);
        }
    }
    subsize[curr]=tim-tim1;
}

void build(ll nod,ll tl,ll tr)
{
    if(tl==tr)
    {
        t[nod]=value[tl];
        return;
    }
    ll tm=(tl+tr)/2;
    build(nod*2,tl,tm);
    build(nod*2+1,tm+1,tr);
    t[nod]=t[nod*2]+t[nod*2+1];
}

void update(ll nod,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        t[nod]=val;
        return;
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)
        update(nod*2,tl,tm,pos,val);
    else
        update(nod*2+1,tm+1,tr,pos,val);
    t[nod]=t[nod*2]+t[nod*2+1];
}

ll query(ll nod,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 0;
    if(l<=tl && r>=tr)
        return t[nod];
    ll tm=(tl+tr)/2;
    return query(nod*2,tl,tm,l,min(r,tm))+query(nod*2+1,tm+1,tr,max(l,tm+1),r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
	    cin>>weight[i];
	    weight[i]=weight[i]*weight[i];
	}
	for(ll u=0;u<(n-1);u++)
	{
	    ll a,b;
	    cin>>a>>b;
	    adj[a].eb(b);
	    adj[b].eb(a);
	}
	dfs(1);
	build(1,0,n-1);
	ll q;
	cin>>q;
	while(q--)
	{
	  ll typ;
	  cin>>typ;
	  if(typ==1)
	  {
	      ll pp,vv;
	      cin>>pp>>vv;
	      ll pp1=timedata[pp];
	      update(1,0,n-1,pp1,vv*vv);
	  }
	  else
	  {
	      ll pp;
	      cin>>pp;
	      ll pp1=timedata[pp];
	      ll subs=subsize[pp];
	      ll pp2=pp1+subs-1;
	      cout<< query(1,0,n-1,pp1,pp2)<<endl;
	  }
	}
    return 0;
}


//252908XL