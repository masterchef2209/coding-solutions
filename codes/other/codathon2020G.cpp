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
 
//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
 
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
 
#define fi first
#define se second
 
#define SSIZE 1000005
#define MAXN 1000005
 
#define int long long
#define lli long long
 
ll n;

lli fen[1000005];
lli a[1000005];
void inc(lli i,lli val)
{
    for(;i<=1000005;i+=(i&(-i)))
    fen[i]+=val;
}
lli sum(lli i)
{
    lli ans=0;
    for(;i>0;i-=(i&(-i)))
    ans+=fen[i];
    return ans;
}
 
int spf[MAXN]; 
 
void precompute() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    set<int>ss;
    while (x != 1) 
    { 
        ss.insert(spf[x]); 
        x = x / spf[x]; 
    } 
    for(auto &yo:ss)
    {
        ret.emplace_back(yo);
    }
    return ret; 
} 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll arr[100002];
    precompute();
    ll q;
    cin>>q;
    while(q--)
    {
        ll typ;
        cin>>typ;
        if(typ==1)
        {
            ll x;
            cin>>x;
            vector<ll>tem=getFactorization(x);
            for(auto &noo:tem)
            {
                inc(noo,a[noo]+1);
            }
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            cout<<(sum(r)-sum(l-1))<<"\n";
        }
    }
    return 0;
}
 
 
//252908XL