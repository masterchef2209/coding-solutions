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

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
#define int long long
#define fi first
#define se second
#define N 10005
struct Point
{
	double x, y;

	Point operator -(Point p)
	{
		return {x-p.x, y-p.y};
	}

	double dist()
	{
		return sqrt(x*x + y*y);
	}
};

bool by_x(Point &a, Point &b)
{
	return a.x < b.x;
}

bool by_y(Point &a, Point &b)
{
	return a.y < b.y;
}

int n;
double ans=1e18;
Point pt[N];

double solve(int L, int R)
{
	if(L==R)
		return 1e18;
	int M=(L+R)/2;
	double d=min(solve(L, M), solve(M+1, R));
	double midx=pt[L+(R-L+1)/2].x;
	vector<Point> v;
	for(int i=L;i<=R;i++)
	{
		if(Point{pt[i].x-midx, 0}.dist()<d)
		{
			v.push_back(pt[i]);
		}
	}
	sort(v.begin(), v.end(), by_y);
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(Point{0, v[i].y-v[j].y}.dist()>d)
				break;
			d=min(d, (v[i]-v[j]).dist());
		}
	}
	return d;
}  

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	while(cin>>n)
	{
		if(n==0)
			break;
		for(int i=1;i<=n;i++)
		{
			double xx,yy;
			cin>>xx>>yy;
			pt[i]={xx,yy};
		}
		sort(pt+1,pt+1+n,by_x);
		double ans=solve(1,n);
		if(ans>=10000)
			cout<<"INFINITY"<<endl;
		else
			cout<<fixed<<setprecision(4)<<ans<<endl;
	}
    return 0;
}