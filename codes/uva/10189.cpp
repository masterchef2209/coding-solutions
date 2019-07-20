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

char grid[110][110];

ll dx[8]={0,0,1,1,1,-1,-1,-1};
ll dy[8]={1,-1,1,0,-1,1,0,-1};

ll n,m;

inline bool ingrid(ll xx,ll yy)
{
	return (xx>=0 && yy>=0 && xx<n && yy<m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll test=1;
	while(cin>>n>>m)
	{
	    if(n==0 && m==0)
	        break;
	    if(test>1)
	        cout<<"\n";
	    cout<<"Field #"<<test++<<":\n";
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			{
				cin>>grid[i][j];
			}
		}
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			{
				if(grid[i][j]=='*')
				{
					cout<<"*";
				}
				else
				{
					ll sum=0;
					for(ll k=0;k<8;k++)
					{
						ll cx=i+dx[k];
						ll cy=j+dy[k];
						if(ingrid(cx,cy) && grid[cx][cy]=='*')
						{
							sum++;
						}
					}
					cout<<sum;
				}
			}
			cout<<"\n";
		}
	}
    return 0;
}