		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>

//not accepted

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

ll n;

map< ll,ll>mm,mm1;

ll sieve[3000005]={0};
vector<ll>primes;

void precompute(){
	for(ll i=2;i<3000005;i++){
		if(sieve[i]==0){
			// cout<<i<<endl;
			primes.emplace_back(i);
			for(ll j=i+i;j<3000005;j+=i){
				if(sieve[j]==0)
					sieve[j]=i;
			}
		}
	}
}

vector<ll>arr;

ll compute(ll num)
{
	if(sieve[num]==0)
	{
		return primes[num-1];
	}
	else
	{
		for(ll i=2;i<=num;i++)
		{
			if(num%i==0)
			{
				return (num/i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	precompute();
	cin>>n;
	for(ll i=0;i<2*n;i++)
	{
		ll val;
		cin>>val;
		arr.eb(val);
		mm1[val]++;
		if(val>200000) continue;
		ll val1=compute(val);
 		//cout<<val1<<endl;
 		mm[val]=val1;
	}
 	for(auto &y:arr)
 	{ 	
 	    ll ch=mm1[y];
 	    if(ch>0)
	    {
 			ll val=y;
 			ll val1=mm[val];
 			//cout<<val<<" "<<val1<<endl;
 			if(mm1.find(val1)!=mm.end() && mm1[val1]>0)
 			{
 				mm1[val1]--;
 				cout<<val<<" ";
 				mm1[val]--;
 			}
 		}
 	}
    return 0;
}