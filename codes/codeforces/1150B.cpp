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

int n;

char grid[55][55];

inline bool ingrid(int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<n);
}

int dr[4]={1,1,1,2};
int dc[4]={-1,0,1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	for(int i=0;i<n-2;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(grid[i][j]=='.')
			{
			    grid[i][j]='#';
				int count1=0;
				for(int c=0;c<4;c++)
				{
					int i1=i+dr[c];
					int j1=j+dc[c];
					if(ingrid(i1,j1) && grid[i1][j1]=='.')
					{
						grid[i1][j1]='#';
						count1++;
					}
				}
				if(count1!=4)
				{
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		    //cout<<grid[i][j]<<" ";
			if(grid[i][j]=='.')
			{
			    cout<<"NO";
			    return 0;
			}
		}
		//cout<<endl;
	}
	cout<<"YES";
    return 0;
}