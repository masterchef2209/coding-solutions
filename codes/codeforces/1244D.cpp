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

vector< vector<ll> >adj(100005);

vector<ll>data;

void dfs(ll curr,ll prev)
{
    data.eb(curr);
    for(auto &nei:adj[curr])
    {
        if(nei!=prev)
            dfs(nei,curr);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>c1(n+3,0),c2(n+3,0),c3(n+3,0);
	vector<ll>degree(n+3,0);
	for(ll i=0;i<n;i++)
	{
		cin>>c1[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>c2[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>c3[i];
	}
	for(ll u=0;u<(n-1);u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
		degree[a]++;
		degree[b]++;
	}
	ll one=0,two=0,lol=0;
	ll myvertex=-1;
	for(ll i=1;i<=n;i++)
	{
		if(degree[i]==1)
		{
			one++;
			myvertex=i;
		}
		else if(degree[i]==2)
			two++;
		else
			lol++;
	}
	if(lol!=0)
	{
		cout<<"-1\n";
	}
	else
	{
		if(one==2 && two==(n-2))
		{
		    dfs(myvertex,0);
		  //  for(auto &x:data)
		  //  {
		  //      cout<<x<<" ";
		  //  }
		  //  cout<<endl;
			ll ans=LLONG_MAX;
			vector<ll>frick;
			vector<ll>hehe;
			frick.eb(1);
			frick.eb(2);
			frick.eb(3);
			do
			{
				ll sum=0;
				for(ll i=0;i<n;i++)
				{
					ll pos=i%3;
					ll bal=frick[pos];
					if(bal==1)
					{
						sum+=c1[data[i]-1];
					}
					else if(bal==2)
					{
						sum+=c2[data[i]-1];
					}
					else
					{
						sum+=c3[data[i]-1];
					}
				}
				if(sum<ans)
				{
				    hehe=frick;
				}
				ans=min(ans,sum);
			}while(next_permutation(frick.begin(),frick.end()));
			cout<<ans<<"\n";
			vector<ll>colur(n+3,0);
			for(ll i=0;i<n;i++)
			{
			    colur[data[i]]=hehe[i%3];
			    //cout<<hehe[i%3]<<" ";
			}
			for(ll i=1;i<=n;i++)
			{
			    cout<<colur[i]<<" ";
			}
			cout<<"\n";
		}
		else
		{
			cout<<"-1\n";
		}
	}
    return 0;
}


//252908XL