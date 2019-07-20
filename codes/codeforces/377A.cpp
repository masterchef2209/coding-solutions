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

char grid[510][510];
ll visited[510][510];

ll n,m,k1;

ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};

inline bool ingrid(ll x,ll y)
{
    return (x>=1 && x<=n && y>=1 && y<=m);
}

void bfs(ll sx,ll sy)
{
    queue< pair<ll,ll> >Q;
    visited[sx][sy]=1;
    Q.push(mp(sx,sy));
    while(!Q.empty() && k1--)
    {
        pair< ll,ll >point=Q.front();
        Q.pop();
        grid[point.fi][point.se]='F';
        for(ll k=0;k<4;k++)
        {
            ll px=point.fi+dx[k];
            ll py=point.se+dy[k];
            if(ingrid(px,py) && visited[px][py]==0 && grid[px][py]=='.')
            {
                visited[px][py]=1;
                Q.push(mp(px,py));
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k1;
	ll s=0;
	ll sx,sy;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='.')
			{
			    s++;
			    sx=i;
			    sy=j;
			}
		}
	}
	k1=s-k1;
	bfs(sx,sy);
	for(ll i=1;i<=n;i++)
	{
	    for(ll j=1;j<=m;j++)
	    {
	        if(grid[i][j]=='.')
	        {
	            cout<<"X";
	        }
	        else if(grid[i][j]=='F')
	        {
	            cout<<".";
	        }
	        else
	            cout<<grid[i][j];
	    }
	    cout<<"\n";
	}
    return 0;
}


//252908XL