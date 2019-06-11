		/*Read the problem carefully before starting to work on it*/
//i give up
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

#define int long long

const int N=1e5+5;

ll back[N];
ll isgood[N]={0},dp[N]={0},sum[N]={0},sum2[N]={0};

void kmpPreprocess(string P) {
    ll j = -1;
    back[0] = -1;
    for (ll i = 0; i < P.size(); i++) {
        while (j >= 0 && P[i] != P[j]) {
            j = back[j];
        }
        j++;
        back[i + 1] = j;
    }
}
vector<ll> kmpSearch(string S, string P) {
    vector<ll> res;
    ll j = 0;
    for (ll i = 0; i < S.size(); i++) {
        while (j >= 0 && S[i] != P[j]) {
            j = back[j];
        }
        j++;
        if (j == P.size()) {
            res.push_back(i);
            j = back[j];
        }
    }
    return res;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,t;
	cin>>s>>t;
	kmpPreprocess(t);
	vector<int>positions=kmpSearch(s,t);
	if (positions.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
	for(auto &x:positions)
	{
		isgood[x]=1;
	}
	if(isgood[0])
	{
		dp[0]=sum[0]=sum2[0]=1;
	}
	for(int i=1;i<s.size();i++)
	{
		if(isgood[i])
		{
			dp[i]=(sum2[i-t.size()]+(i-t.size()+1+1) )%mod;
		}
		else
		{
			dp[i]=dp[i-1];
		}
		sum[i]=(dp[i]+sum[i-1])%mod;
		sum2[i]=(sum[i]+sum2[i-1])%mod;
	}
	ll ans=0;
	for(ll i=0;i<s.size();i++)
	{
		ans=(ans+dp[i])%mod;
	}
	cout<<ans;
    return 0;
}