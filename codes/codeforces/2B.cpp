		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>

//very good question

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

ll n;

#define N 1005

ll arr[N][N],dp1[N][N],dp2[N][N];

void special_case(ll x,ll y)
{
	ll xx=0,yy=0;
	while(xx!=x)
	{
		cout<<"D";
		xx++;
	}
	while(yy!=y)
	{
		cout<<"R";
		yy++;
	}
	while(xx!=(n-1))
	{
		cout<<"D";
		xx++;
	}
	while(yy!=(n-1))
	{
		cout<<"R";
		yy++;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll flag=0;
	ll zx=-1,zy=-1;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==0)
			{
				flag=1;
				zx=i;
				zy=j;
				arr[i][j]=10;
			}
			ll tmp=arr[i][j],tmp1=arr[i][j];
			ll c2=0,c5=0;
			while(tmp>1 && tmp%2==0)
			{
				c2++;
				tmp/=2;
			}
			while(tmp1>1 && tmp1%5==0)
			{
				c5++;
				tmp1/=5;
			}
			dp1[i][j]=c2;
			dp2[i][j]=c5;
		}
	}
	for(int i=1;i<n;i++)
	{
		dp1[i][0]+=dp1[i-1][0];
		dp1[0][i]+=dp1[0][i-1];
		dp2[i][0]+=dp2[i-1][0];
		dp2[0][i]+=dp2[0][i-1];
	}
	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<n;j++)
		{
			dp1[i][j]+=min(dp1[i-1][j],dp1[i][j-1]);
			dp2[i][j]+=min(dp2[i-1][j],dp2[i][j-1]);
		}
	}
	if(dp1[n-1][n-1]<dp2[n-1][n-1])
	{
		if(flag==1 && dp1[n-1][n-1]>1)
		{
			cout<<"1\n";
			special_case(zx,zy);
			return 0;
		}
		cout<<dp1[n-1][n-1]<<"\n";
		stack<char>ans;
		ll x=n-1,y=n-1;
		while(x!=0 && y!=0)
		{
			if(dp1[x-1][y]<dp1[x][y-1])
			{
				ans.push('D');
				x--;
			}
			else
			{
				ans.push('R');
				y--;
			}
		}
		while(x!=0)
		{
			ans.push('D');
			x--;
		}
		while(y!=0)
		{
			ans.push('R');
			y--;
		}
		while(!ans.empty())
		{
			cout<<ans.top();
			ans.pop();
		}
	}
	else
	{
		if(flag==1 && dp2[n-1][n-1]>1)
		{
			cout<<"1\n";
			special_case(zx,zy);
			return 0;
		}
		cout<<dp2[n-1][n-1]<<"\n";
		stack<char>ans;
		ll x=n-1,y=n-1;
		while(x!=0 && y!=0)
		{
			if(dp2[x-1][y]<dp2[x][y-1])
			{
				ans.push('D');
				x--;
			}
			else
			{
				ans.push('R');
				y--;
			}
		}
		while(x!=0)
		{
			ans.push('D');
			x--;
		}
		while(y!=0)
		{
			ans.push('R');
			y--;
		}
		while(!ans.empty())
		{
			cout<<ans.top();
			ans.pop();
		}
	}
    return 0;
}