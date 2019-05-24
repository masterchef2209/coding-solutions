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

const int MAX =500005 ;
long long size[MAX];
int arr[MAX];

vector<ll>arr1(500005,1);

void initialize()
{
  for(int i=0;i<MAX;i++)
  {
    arr[i]=i;
    size[i]=1;
  }
}

int root(int i)
{
  while(i!=arr[i])
  {
    arr[i]=arr[arr[i]];
    i=arr[i];
  }
return i;
}

void dsu(int a,int b)
{
  int rootA=root(a);
  int rootB=root(b);
  if(size[rootA]<size[rootB])
  {
    arr[rootA]=arr[rootB];
    size[rootB]+=size[rootA];
  }
  else
  {
    arr[rootB]=arr[rootA];
    size[rootA]+=size[rootB];
  }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	initialize();
	ll n,m;
	cin>>n>>m;
	for(ll u=0;u<m;u++)
	{
		ll si;
		cin>>si;
		vector<ll>arr2(si);
		ll tmp=0;
		for(ll i=0;i<si;i++)
		{
			cin>>arr2[i];
		}
		for(ll i=1;i<si;i++)
		{
		    dsu(arr2[i],arr2[i-1]);
		}
// 		for(ll i=0;i<si;i++)
// 	    {
// 	        arr[root(arr2[i])]++;
// 	        cout<<root(arr2[i])<<" "<<arr2[i]<<endl;
// 	    }
	}
// 	for(ll i=1;i<=n;i++)
// 	{
// 	    cout<<arr[root(i)]<<" ";
	    
// 	}
    for(ll i=1;i<=n;i++)
	{
	    cout<<size[root(i)]<<" ";
	    
	}
    return 0;
}