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

char grid[105][2005];
char arr[5]={'a','e','i','o','u'};
char arr1[5]={'a','u','o','i','e'};
ll num1=-1,num2=-1;
inline bool ingrid(ll i,ll j)
{
    return (i>=1 && j>=1 && i<=num1 && j<=num2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll k;
	cin>>k;
	if(k<25)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	for(ll i=5;i<=k;i++)
	{
		if( (k%i==0) && ((k/i)>=5))
		{
			num1=i;
			num2=(k/i);
			break;
		}
	}
	if(num1==-1)
		cout<<-1;
	else
	{
		for(ll col=1;col<=num2;col++)
		{
			ll i=1,j=col;
			while(ingrid(i,j))
			{
				grid[i][j]=arr[((col-1)%5)];
				i++;j++;
			}
		}
		for(ll row=1;row<=num1;row++)
		{
			ll i=row,j=1;
			while(ingrid(i,j))
			{
				grid[i][j]=arr1[((row-1)%5)];
				i++;j++;
			}
		}
		string ans("");
		for(ll i=1;i<=num1;i++)
		{
			for(ll j=1;j<=num2;j++)
			{
			//	cout<<grid[i][j]<<" ";
				ans+=grid[i][j];
			}
		//	cout<<endl;
		}
		cout<<ans;
	}
    return 0;
}