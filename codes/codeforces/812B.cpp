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
#define flor floor

vector< pair<ll,ll> >lights(16);

ll n1=-1,flag=0;
ll n,m;

ll func(ll floor,ll side)
{
	if(floor==n1)
	{
	    if(side==0)
	    {
		    if(lights[floor].se==-1)
			    return 0;
		    return ( (lights[floor].se-1) );
	    }
	    else
	    {
		    if(lights[floor].fi==1000)
			    return 0;
		    return ( (m-lights[floor].fi) );
	    }
	}
	if(side==0)
	{
		if(lights[floor].se==-1)
			return func(floor+1,0);
		return ( (lights[floor].se-1) + min( (lights[floor].se-1)+func(floor+1,0),(m-lights[floor].se)+func(floor+1,1) ) );
	}
	else
	{
		if(lights[floor].fi==1000)
			return func(floor+1,1);
		return ( (m-lights[floor].fi)+min( (m-lights[floor].fi)+func(floor+1,1) , (lights[floor].fi-1) + func(floor+1,0)  ) );
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	m+=2;
	for(ll i=1;i<=n;i++)
	{
		lights[i].fi=1000;
		lights[i].se=-1;
	}
	for(ll i=n;i>=1;i--)
	{
		for(ll j=1;j<=m;j++)
		{
			char bulb;
			cin>>bulb;
			if(bulb-'0')
			{
				if(flag==0)
				{
					n1=i;
					flag=1;
				}
				lights[i].fi=min(lights[i].fi,j);
				lights[i].se=max(lights[i].se,j);
			}
		}

	}
//	cout<<lights[1].fi<<" "<<lights[1].se<<endl;
//	cout<<n1<<endl;
	if(n1==-1)
		cout<<0;
	else
		cout<<(n1-1+func(1,0) );
    return 0;
}