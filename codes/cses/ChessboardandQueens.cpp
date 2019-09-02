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

char grid[8][8];

ll colu[8];
ll d1[15];
ll d2[15];

ll ans=0;

void f(ll row)
{
	if(row==8)
	{
		ans++;
	}
	else
	{
		for(ll col=0;col<8;col++)
		{
			if(grid[row][col]=='*')
				continue;
			if(d1[row+col]==0 && colu[col]==0 && d2[row-col+7]==0)
			{
				d1[row+col]=colu[col]=d2[row-col+7]=1;
				f(row+1);
				d1[row+col]=colu[col]=d2[row-col+7]=0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(ll i=0;i<8;i++)
	{
		for(ll j=0;j<8;j++)
		{
			cin>>grid[i][j];
		}
	}
	f(0);
	cout<<ans;
    return 0;
}


//252908XL