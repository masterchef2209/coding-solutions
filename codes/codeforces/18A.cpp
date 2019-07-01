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

//#define fi1 ifstream cin("input.txt")
//#define of1 ofstream cout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};

bool isRightTriangle(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
	vector<ll>dist;
	dist.eb((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	dist.eb((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	dist.eb((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	sort(dist.begin(),dist.end());
	if(dist[2]==(dist[0]+dist[1]))
		return true;
	return false;
}

bool f(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
    if(x1==x2 && y1==y2)
        return false;
    if(x1==x3 && y1==y3)
        return false;
    if(x3==x2 && y3==y2)
        return false;
	ll temp=(y3-y2)*(x1-x2)-(x3-x2)*(y1-y2);
	if(temp==0)
		return false;
	return  true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	if(isRightTriangle(x1,y1,x2,y2,x3,y3))
	{
		cout<<"RIGHT";
		return 0;
	}
	for(int i=0;i<4;i++)
	{
		if(isRightTriangle(x1+dx[i],y1+dy[i],x2,y2,x3,y3) && f(x1+dx[i],y1+dy[i],x2,y2,x3,y3))
		{
	      //  cout<<x1+dx[i]<<" "<<y1+dy[i]<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
			cout<<"ALMOST";
			return 0;
		}
		if(isRightTriangle(x1,y1,x2+dx[i],y2+dy[i],x3,y3) && f(x1,y1,x2+dx[i],y2+dy[i],x3,y3))
		{
		   // cout<<x1<<" "<<y1<<" "<<x2+dx[i]<<" "<<y2+dy[i]<<" "<<x3<<" "<<y3<<endl;
			cout<<"ALMOST";
			return 0;
		}
		if(isRightTriangle(x1,y1,x2,y2,x3+dx[i],y3+dy[i]) && f(x1,y1,x2,y2,x3+dx[i],y3+dy[i]))
		{
		   // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3+dx[i]<<" "<<y3+dy[i]<<endl;
			cout<<"ALMOST";
			return 0;
		}
	}
	cout<<"NEITHER";
    return 0;
}