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

ll n,m;

ll visited[22][22]={0};

ll row[22];

ll col[22];

inline bool ingrid(ll x,ll y)
{
	return (x>=1 && x<=n && y>=1 && y<=m);
}

void dfs(ll x,ll y)
{
	visited[x][y]=1;
	ll x1=x+col[y];
	ll y1=y+row[x];
	if(ingrid(x,y1) && visited[x][y1]==0)
		dfs(x,y1);
	if(ingrid(x1,y) && visited[x1][y]==0)
		dfs(x1,y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	string s1,s2;
	cin>>s1>>s2;
	for(ll i=0;i<s1.size();i++)
	{
		if(s1[i]=='>')
			row[i+1]=1;
		else
			row[i+1]=-1;
	}
	for(ll i=0;i<s2.size();i++)
	{
		if(s2[i]=='^')
			col[i+1]=-1;
		else
			col[i+1]=1;
	}
	
	for(ll i=1;i<=n;i++)
	{
	   for(ll j=1;j<=m;j++)
	   {
	       for(ll a=1;a<=n;a++)
	       for(ll b=1;b<=m;b++)
	        visited[a][b]=0;
	       dfs(i,j);
	       for(ll a=1;a<=n;a++)
	       for(ll b=1;b<=m;b++)
	        if(visited[a][b]==0)
	        {
	            cout<<"NO";
	            return 0;
	        }
	   }
	}
	
	cout<<"YES";
    return 0;
}


//252908XL