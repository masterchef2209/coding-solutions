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

int sieve[2750133];
multiset<ll>b,a;


void precompute()
{
	sieve[0]=sieve[1]=1;
	for(ll i=2;i*i<=2750133;i++)
	{
		if(sieve[i]==0)
		{
			for(ll j=2*i;j<=2750133;j+=i)
			{
				sieve[j]=1;
			}
		}
	}
	ll lol=1;
	for(ll i=2;i<=2750133;i++)
	{
		if(sieve[i]==0)
		{
			sieve[i]=lol++;
		}
		else
		{
		    sieve[i]=0;
		}
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	precompute();
	ll n;
	cin>>n;
	for(ll i=0;i<2*n;i++)
	{
		ll tmp;
		cin>>tmp;
		b.insert(tmp);
	}
	for(auto it=b.rbegin();it!=b.rend();it++)
	{
		if(sieve[*it]!=0)
		{
			a.insert(sieve[*it]);
			b.erase(b.find(sieve[*it]));
			//cout<<*it<<" "<<pos+1<<endl;
		}
		else
		{
            ll val=*it;
            for(ll i=2;i<=val;i++)
            {
                if(val%i==0)
                {
                    b.erase(b.find(val/i));
                    break;
                }
            }
            a.insert(val);
		}
	}
	for(auto &x:a)
	{
	    cout<<x<<" ";
	}
    return 0;
}