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

ll A[55][55];
ll B[55][55];

vector<pair<ll,ll> >ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>A[i][j];
		}
	}
	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<m;j++)
		{
			if(A[i][j]==1 && A[i+1][j]==1 && A[i][j+1]==1 && A[i+1][j+1]==1)
			{
				if(B[i][j]==0 || B[i+1][j]==0 || B[i][j+1]==0 || B[i+1][j+1]==0)
				{
					B[i][j]=B[i+1][j]=B[i][j+1]=B[i+1][j+1]=1;
					ans.eb(i,j);
				}
			}
		}
	}
	int flag=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(A[i][j]!=B[i][j])
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
			break;
	}
	ll ssize=ans.size();
	if(flag==0)
	{
		cout<<-1;
	}
	else
	{
		if(ssize>=0 && ssize<=2500)
		{
			cout<<ssize<<"\n";
			for(auto &x:ans)
			{
				cout<<x.fi<<" "<<x.se<<"\n";
			}
		}
		else
		{
			cout<<-1;
		}
	}
    return 0;
}


//252908XL