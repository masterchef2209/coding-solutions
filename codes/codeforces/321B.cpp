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

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

vector<ll>cel,jiroa,jirob;
multiset<ll>cel1;

ll part()
{
	sort(jiroa.begin(),jiroa.end());
	sort(cel.rbegin(),cel.rend());
	ll sum=0;
	for(ll i=0;i<min(jiroa.size(),cel.size());i++)
	{
		sum+=max(0LL,(cel[i]-jiroa[i]));
	}
	return sum;
}

ll full()
{
	if((jiroa.size()+jirob.size())>cel.size())
		return 0;
	for(auto &x:jirob)
	{
		auto it=cel1.upper_bound(x);
		if(it==cel1.end())
			return 0;
		cel1.erase(it);
	}
	ll po=0;
	for(auto it=cel1.rbegin();it!=cel1.rend();it++)
		cel[po++]=*it;
	sort(jiroa.rbegin(),jiroa.rend());
	if(jiroa.size()>cel1.size())
		return 0;
	ll i=0;
	ll ret=0;
	for(i=0;i<jiroa.size();i++)
	{
		if(cel[i]>=jiroa[i]);
		else
			return 0;
	}
	for(i=0;i<cel1.size();i++)
	{
		ret+=cel[i];
	}
	for(i=0;i<jiroa.size();i++)
	{
		ret-=jiroa[i];
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		string s;
		ll tmp;
		cin>>s>>tmp;
		if(s[0]=='A')
		{
			jiroa.eb(tmp);
		}
		else
		{
			jirob.eb(tmp);
		}
	}
	for(ll i=0;i<m;i++)
	{
		ll tmp;
		cin>>tmp;
		cel.eb(tmp);
		cel1.insert(tmp);
	}
	ll ans=part();
	ans=max(ans,full());
	cout<<ans<<endl;
    return 0;
}