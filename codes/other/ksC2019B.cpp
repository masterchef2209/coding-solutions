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

#define int long long
#define fi first
#define se second

ll grid[310][310];
ll dp[310][310]={0};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(ll u=1;u<=t;u++)
    {
        ll r,c,k;   
        cin>>r>>c>>k;
        for(ll i=1;i<=r;i++)
        {
            for(ll j=1;j<=c;j++)
            {
                dp[j][i]=0;
                cin>>grid[i][j];
            }
        }
        for(int i=1;i<=r;i++)
        {
            dp[1][i]=1;
            for(int en=2;en<=c;en++)
            {
                ll st=en-1;
                ll mm=max(grid[i][st],grid[i][en]);
                ll mm1=min(grid[i][st],grid[i][en]);
                while(mm-mm1<=k && st>=1)
                {
                    st--;
                    mm=max(grid[i][st],mm);
                    mm1=min(grid[i][st],mm1);
                }
                dp[en][i]=en-st;
            }
        }
        ll ans=0;
        for(int en=1;en<=c;en++)
        {
            for(ll yo1=1;yo1<=r;yo1++)
            {
                ll uwu=dp[en][yo1];
                for(ll yo2=yo1;yo2<=r;yo2++)
                {
                    uwu=min(uwu,dp[en][yo2]);
                    ans=max(ans,uwu*(yo2-yo1+1));
                }
            }
        }
        cout<<"Case #"<<u<<": "<<ans<<endl;
    }
    return 0;
}