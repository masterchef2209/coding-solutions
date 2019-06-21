		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

#define bip(n) __builtin_popcount(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctz(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clz(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffs(n)//index of first one bit!!

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream cin("input.txt")
//#define of1 ofstream cout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector< vector< pair<ll,ll> > >points(26);
		char grid[n+1][m+1];
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=m;j++)
			{
				cin>>grid[i][j];
				if(isalpha(grid[i][j]))
				{
					points[grid[i][j]-'a'].eb(i,j);
				}
			}
		}
		for(ll i=0;i<26;i++)
		{
			sort(points[i].begin(),points[i].end());
		}
		int flag=0;
		vector< pair< pair<ll,ll> ,pair<ll,ll> > >ans;
	    for(ll i=0;i<26;i++)
 		{
 		    if(points[i].size()==0)
 		        continue;
 		    pair<ll,ll> one=points[i][0];
 			pair<ll,ll> two=points[i][points[i].size()-1];
 			if(one.fi==two.fi)
 			{
 			    for(auto &x:points[i])
 			    {
 			        if(x.fi!=one.fi)
 			        {
 			            flag=1;
 			            break;
 			        }
 			    }
 			}
 			else if(one.se==two.se)
 			{
 			    for(auto &x:points[i])
 			    {
 			        if(x.se!=one.se)
 			        {
 			            flag=1;
 			            break;
 			        }
 			    }
 			}
 			else
 			{
 			    flag=1;
 			    break;
 			}
 			if(flag)
 			    break;
 		}
 		if(flag)
 		{
 		    cout<<"NO\n";
 		    continue;
		}
		ll nono=0;
		for(ll i=0;i<26;i++)
		{
		    if(points[i].size()==0)
		    {
		        ans.eb(mp(0,0),mp(0,0));
		        continue;
		    }
		    nono=max(i+1,nono);
			pair<ll,ll> one=points[i][0];
			pair<ll,ll> two=points[i][points[i].size()-1];
			if(one.fi==two.fi)
			{
				for(ll j=one.se;j<=two.se;j++)
				{
					if((grid[one.fi][j]-'a')>=i);
					else
					{
						flag=1;
						break;
					}
				}
			}
			else if(one.se==two.se)
			{
				for(ll j=one.fi;j<=two.fi;j++)
				{
					if((grid[j][one.se]-'a')>=i);
					else
					{
						flag=1;
						break;
					}
				}
			}
			else
			{
			    flag=1;
			    break;
			}
			if(flag)
				break;
			ans.eb(one,two);
		}
		if(flag)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			cout<<nono<<"\n";
			for(int i=0;i<nono;i++)
			{
			    if(ans[i].fi.fi==0)
			    {
			        cout<<ans[nono-1].fi.fi<<" "<<ans[nono-1].fi.se<<" "<<ans[nono-1].se.fi<<" "<<ans[nono-1].se.se<<endl;
			    }
			    else
			    {
			        cout<<ans[i].fi.fi<<" "<<ans[i].fi.se<<" "<<ans[i].se.fi<<" "<<ans[i].se.se<<endl;
			    }
			}
		}
	}
    return 0;
}