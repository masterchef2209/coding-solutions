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

inline bool ingrid(pair<ll,ll>&pp)
{
    return (pp.fi>=1 && pp.se>=1 && pp.fi<=n && pp.se<=m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	char grid[n+1][m+1];
	bool visited[n+1][m+1];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>grid[i][j];
			visited[i][j]=false;
		}
	}
	stack< pair<ll,ll> >st;
	st.push(mp(1,1));
	while(!st.empty())
	{
		pair<ll,ll>pp=st.top();
		st.pop();
		visited[pp.fi][pp.se]=true;
		if(pp.fi==n && pp.se==m)
			break;
		pair<ll,ll>down=mp(pp.fi+1,pp.se);
		pair<ll,ll>right=mp(pp.fi,pp.se+1);
		if(ingrid(down) && grid[down.fi][down.se]=='.' && !visited[down.fi][down.se])
		{
			st.push(down);
		}
		if(ingrid(right) && grid[right.fi][right.se]=='.' && !visited[right.fi][right.se])
		{
			st.push(right);
		}
	}
	if(!visited[n][m])
	{
		cout<<0;
	}
	else
	{
		while(!st.empty())
		    st.pop();
		st.push(mp(1,1));
		visited[n][m]=false;
		while(!st.empty())
		{
			pair<ll,ll>pp=st.top();
			st.pop();
			visited[pp.fi][pp.se]=true;
			if(pp.fi==n && pp.se==m)
				break;
			pair<ll,ll>down=mp(pp.fi+1,pp.se);
			pair<ll,ll>right=mp(pp.fi,pp.se+1);
			if(ingrid(right) && grid[right.fi][right.se]=='.' && !visited[right.fi][right.se])
			{
				st.push(right);
			}
			if(ingrid(down) && grid[down.fi][down.se]=='.' && !visited[down.fi][down.se])
			{
				st.push(down);
			}
		}
		if(visited[n][m])
		{
			cout<<2;
		}
		else
		{
			cout<<1;
		}
	}
    return 0;
}


//252908XL