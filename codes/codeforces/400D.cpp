		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

//not accepted

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

#define INF INT_MAX

ll dp[505][505];
vector<ll>type(100005);

ll parent[100005];
ll size[100005];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,k;
	cin>>n>>m>>k;
	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=k;j++)
		{
			dp[i][j]=INF;
		}
	}
	ll ty=1;
	for(ll i=1;i<=n;i++)
	{
	    make_set(i);
	}
	for(ll i=1;i<=n;)
	{
		ll tmp;
		cin>>tmp;
		while(tmp-- && i<=n)
		{
			type[i++]=ty;
		}
		ty++;
	}
	for(ll u=0;u<m;u++)
	{
		ll a1,b1,x;
		cin>>a1>>b1>>x;
		ll a,b;
		a=type[a1];
		b=type[b1];
		dp[a][b]=min(dp[a][b],x);
		dp[b][a]=min(dp[b][a],x);
		if(x==0)
		{
			union_sets(a1,b1);
		}
	}
	for(ll i=1;i<=n;)
	{
		if(i==1 || type[i]!=type[i-1])
		{
		    ll j;
		    for(j=i+1;j<=n && type[j]==type[i];j++)
		    {
		        if(find_set(i)!=find_set(j))
		        {
		            cout<<"No";
		            return 0;
		        }
		    }
		    i=j;
		}
	}
	cout<<"Yes\n";
	for(ll i=1;i<=k;i++)
	{
		dp[i][i]=0;
	}
	for(ll k1=1;k1<=k;k1++)
	{
		for(ll i=1;i<=k;i++)
		{
			for(ll j=1;j<=k;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k1]+dp[k1][j]);
			}
		}
	}
	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=k;j++)
		{
			if(dp[i][j]==INF)
			{
				cout<<"-1 ";
			}
			else
			{
				cout<<dp[i][j]<<" ";
			}
		}
		cout<<endl;
	}
    return 0;
}