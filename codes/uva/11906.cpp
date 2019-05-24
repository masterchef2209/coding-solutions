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

typedef pair<ll, ll> ii;
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
ll r,c,m,n;
ll grid[110][110]={0};

ll even=0,odd=0;

//ll dx[4]={1,-1,0,0};
//ll dy[4]={0,0,1,-1};

inline bool ingrid(ll a,ll b)
{
	return (a>=0 && b>=0 && a<r && b<c);
}

void bfs(ll m,ll n)
{
	ll dxx[8]={m,m,-m,-m,n,-n,n,-n};
	ll dyy[8]={n,-n,n,-n,m,m,-m,-m};
	queue< pair<ll,ll> >Q;
	grid[0][0]=1;
	Q.push(mp(0,0));
	while(!Q.empty())
	{
		ii pp=Q.front();
		Q.pop();

		    ll temp=0;
		    for(ll i=0;i<8;i++)
		    {
		        if((m==n) && i==4)
		            break;
		        if(n==0)
		            i++;
				ii pp1=mp(pp.fi+dxx[i],pp.se+dyy[i]);
				if(ingrid(pp1.fi,pp1.se) && grid[pp1.fi][pp1.se]!=-1)
				{
					temp++;
				}
				if(m==0 && (i&1))
				    i+=2;
		    }
		    if(temp&1)
			    odd++;
		    else
			    even++;
		for(ll i=0;i<8;i++)
		{
				ii pp2=mp(pp.fi+dxx[i],pp.se+dyy[i]);
				if(ingrid(pp2.fi,pp2.se) && grid[pp2.fi][pp2.se]==0)
				{
					grid[pp2.fi][pp2.se]=1;
					Q.push(pp2);
				}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	for(ll test=1;test<=t;test++)
	{
		even=0,odd=0;
		cin>>r>>c>>m>>n;
		for(ll i=0;i<=r;i++)
		{
			for(ll j=0;j<=c;j++)
			{
				grid[i][j]=0;
			}
		}
		ll w;
		cin>>w;
		for(ll u=0;u<w;u++)
		{
			ll x,y;
			cin>>x>>y;
			grid[x][y]=-1;
		}
		bfs(m,n);
		cout<<"Case "<<test<<": "<<even<<" "<<odd<<endl;
// 		for(ll i=0;i<r;i++)
// 		{
// 		       for(ll j=0;j<c;j++)
// 		       {
// 		            cout<<grid[i][j]<<" ";
// 		       }
// 		       cout<<endl;
// 		}
	}
    return 0;
}