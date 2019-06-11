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

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

char grid[510][510];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int visited[510][510]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll h,w;
	cin>>h>>w;
	for(ll i=1;i<=h;i++)
	{
		for(ll j=1;j<=w;j++)
		{
			cin>>grid[i][j];
		}
	}
	int plusx=-1,plusy=-1;
	int flag=0;
	for(ll i=1;i<=h;i++)
	{
		for(ll j=1;j<=w;j++)
		{
			if(grid[i][j]=='*')
			{
		
				int count=0;
				for(int k=0;k<4;k++)
				{
					int x1=i+dx[k];
					int y1=j+dy[k];
		
					if(x1>=1 && y1>=1 && x1<=h && y1<=w)
					{
						if(grid[x1][y1]=='*')
							count++;
					}
				}
				if(count==4)
				{
					plusx=i;
					plusy=j;
					flag=1;
					break;
				}
		
			}
			if(flag==1)
			    break;
		}
	}
	if(plusx==-1 && plusy==-1)
	{
	    cout<<"NO";
	    return 0;
	}
	visited[plusx][plusy]=1;
	for(int i=plusx+1;i<=h;i++)
	{
	    if(grid[i][plusy]=='*')
	        visited[i][plusy]=1;
	    else break;
	}
	for(int i=plusx-1;i>=1;i--)
	{
	    if(grid[i][plusy]=='*')
	        visited[i][plusy]=1;
	    else break;
	}
	for(int i=plusy+1;i<=w;i++)
	{
	    if(grid[plusx][i]=='*')
	        visited[plusx][i]=1;
	    else break;
	}
	for(int i=plusy-1;i>=1;i--)
	{
	    if(grid[plusx][i]=='*')
	        visited[plusx][i]=1;
	    else break;
	}

	
	for(int i=1;i<=h;i++)
	{
	    for(int j=1;j<=w;j++)
	    {
	        if(grid[i][j]=='*' && visited[i][j]==0)
	        {
	            cout<<"NO";
	            return 0;
	        }
	    }
	}
	cout<<"YES";
    return 0;
}