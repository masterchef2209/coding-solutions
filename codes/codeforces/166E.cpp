		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second
 
typedef vector< vector<ll> > matrix;
 
matrix mul1(const matrix &A,const matrix &B)
{
	matrix C(A.size(),vector<ll>(B[0].size(),0));
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B[0].size();j++)
		{
			for(int k=0;k<A.size();k++)
			{
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
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
		return mul1(A,mpower(A,p-1));
	matrix X=mpower(A,p/2);
	return mul1(X,X);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	matrix T(4,vector<ll>(4));
	T={
								{0,1,1,1},
								{1,0,1,1},
								{1,1,0,1},
								{1,1,1,0}
	};
	T=mpower(T,n);
	matrix M2(1,vector<ll>(4));
	M2={
		{1,0,0,0}
	};
	matrix hehe=mul1(M2,T);
	cout<<hehe[0][0];
    return 0;
}


//252908XL