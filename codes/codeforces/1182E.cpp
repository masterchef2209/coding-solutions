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
const ll mod=1e9+7;

double PI=3.1415926535897932384626;

template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

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

const ll MM=mod-1;

typedef vector< vector<ll> > matrix;


matrix mul(const matrix &A,const matrix &B)
{
	matrix C(A.size(),vector<ll>(B[0].size(),0));
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B[0].size();j++)
		{
			for(int k=0;k<A.size();k++)
			{
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MM;
			}
		}
	}
	return C;
}

matrix mpower(const matrix &A,ll p)
{
	if(p==1)
		return A;
	if(p&1)
		return mul(A,mpower(A,p-1));
	matrix X=mpower(A,p/2);
	return mul(X,X);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll f[4];
	ll n,c;
	cin>>n>>f[1]>>f[2]>>f[3]>>c;
	matrix T(3,vector<ll>(3));
	T={
								{0,1,0},
								{0,0,1},
								{1,1,1}
	};
	// gi=i+logc(fi)
	// gn=g(n-1)+g(n-2)+g(n-3)
	// for matrix exponentiation we wil use modulo as mod-1 because of Euler's theorem
 	T=mpower(T,n-3); // usually it is n-1 but here it is n-3 because we want gn at lowest position of matrix and not at topmost so we will multiply by T^(n-1-2)
	ll deg[4];
	deg[1]=T[2][0];
	deg[2]=T[2][1];
	deg[3]=T[2][2];
	deg[0]=(((deg[1] + 2*deg[2] + 3*deg[3] - n ) % MM ) + MM ) % MM;
	ll ans=power(c,deg[0]);
	for(ll i=1;i<4;i++)
	{
		ans=((power(f[i],deg[i]))%mod*(ans%mod))%mod;
	}
	cout<<ans;
    return 0;
}