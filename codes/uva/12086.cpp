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

#define fi first
#define se second

vector<ll>tree(200005);
vector<ll>arr(200005);
ll n;
void update(ll pos,ll val)
{
	while(pos<=n)
	{
		tree[pos]+=val;
		pos+=(pos&-pos);
	}
}

ll query(ll pos)
{
	ll sum=0;
	while(pos>=1)
	{
		sum+=tree[pos];
		pos-=(pos&-pos);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);\
	ll count=1;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		if(count>1)
			cout<<endl;
		for(ll i=1;i<=n;i++)
		{
			cin>>arr[i];
			tree[i]=0;
		}
		for(ll i=1;i<=n;i++)
		{
			update(i,arr[i]);
		}
		cout<< "Case "<<count++ <<":" <<endl;
		char temp;
		while(cin>>temp)
		{
			if(temp=='E')
		    {
		        char g1,g2;
		        cin>>g1>>g2;
		        break;
		    }
			else if(temp=='S')
			{
			    ll a,b;
				cin>>a>>b;
				ll delta=b-arr[a];
				arr[a]=b;
				update(a,delta);
			}
			else if(temp=='M')
			{
				ll a,b;
				cin>>a>>b;
				if(a==1)
				    cout<<query(b)<<endl;
				else
				    cout<< query(b)-query(a-1) <<endl;
			}
		}
	}
    return 0;
}