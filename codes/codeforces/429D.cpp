#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
//using namespace __gnu_pbds;
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
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
#define int long long
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
#define N 100005
struct Point
{
	int x,y;

	Point operator -(Point p)
	{
		return {x-p.x,y-p.y};
	}

	int dist()
	{
		return x*x+y*y;
	}
};

bool by_x(Point &a,Point&b)
{
	return a.x<b.x;
}

bool by_y(Point&a,Point&b)
{
	return a.y<b.y;
}

int n,ans=LLONG_MAX;
int a[N],pref[N]={0};
Point pt[N];

int solve(int L,int R)
{
	if(L==R)
		return 1e18;
	int M=(L+R)/2;
	int d=min(solve(L,M),solve(M+1,R));
	int midx=pt[L+(R-L+1)/2].x;
	vector<Point>v;
	for(int i=L;i<=R;i++)
	{
		if(Point{pt[i].x-midx,0}.dist()<d)
		{
			v.eb(pt[i]);
		}
	}
	sort(v.begin(),v.end(),by_y);
	for(unsigned int i=0;i<v.size();i++)
	{
		for(unsigned int j=i+1;j<v.size();j++)
		{
			if(Point{0,v[i].y-v[j].y}.dist()>d)
				break;
			d=min(d,(v[i]-v[j]).dist() );
		}
	}
	return d;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]+a[i];
		pt[i]={i,pref[i]};
	}
	sort(pt+1,pt+n+1,by_x);
	int ans=solve(1,n);
	cout<<ans<<endl;
    return 0;
}