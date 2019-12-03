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

ll n;

vector< vector<ll> >lol(4);
map<ll,ll> mm;

vector< vector<ll> >crycry(100005);

map< pair<ll,ll>, vector<ll> > mm1;
vector<ll>visited(100005,0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<(n-2);i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		mm1[mp(a,b)].eb(c);
		mm1[mp(a,c)].eb(b);
		mm1[mp(b,c)].eb(a);
		mm1[mp(b,a)].eb(c);
		mm1[mp(c,a)].eb(b);
		mm1[mp(c,b)].eb(a);
		mm[a]++;
		mm[b]++;
		mm[c]++;
		crycry[a].eb(b);
		crycry[a].eb(c);
		crycry[b].eb(a);
		crycry[b].eb(c);
		crycry[c].eb(a);
		crycry[c].eb(b);
	}
	for(auto &cry:mm)
	{
		if(cry.se==1)
		{
			lol[1].eb(cry.fi);
		}
		else if(cry.se==2)
		{
			lol[2].eb(cry.fi);
		}
		else
		{
			lol[3].eb(cry.fi);
		}
	}
	ll flag=0;
	for(auto &hehe:crycry[lol[1][0]])
	{
	    if(hehe==lol[2][0])
	    {
	        flag=1;
	        break;
	    }
	}
	if(flag==0)
	    swap(lol[2][0],lol[2][1]);
	cout<<lol[1][0];
	cout<<" ";
	cout<<lol[2][0];
	cout<<" ";
	visited[lol[1][0]]=1;
	visited[lol[2][0]]=1;
	ll prev1=lol[1][0];
	ll prev=lol[2][0];
	for(ll i=0;i<(n-2);i++)
	{
	    ll ppu=mm1[mp(prev1,prev)][0];
	    if(visited[ppu]==1)
	    {
	        ppu=mm1[mp(prev1,prev)][1];
	    }
	    cout<<ppu<<" ";
	    visited[ppu]=1;
	    prev1=prev;
	    prev=ppu;
	}
    return 0;
}


//252908XL