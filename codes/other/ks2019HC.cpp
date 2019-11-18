        /*Read the problem carefully before starting to work on it*/
        
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (ll i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        cout<<"Case #"<<test<<": ";
        short dp[200][200][13][13];
        for(ll i=0;i<200;i++)
        for(ll i1=0;i1<200;i1++)
        for(ll j=0;j<11;j++)
        for(ll j1=0;j1<11;j1++)
        {
            dp[i][i1][j][j1]=0;
        }
        vector<ll>arr;
        arr.eb(-1);
        ll n=0;
        for(ll i=1;i<=9;i++)
        {
            ll tmp;
            cin>>tmp;
            if(tmp>=20)
            {
                if(tmp%2==0)
                    tmp=20;
                else
                    tmp=21;
            }
            n+=tmp;
            while(tmp--)
            {
                arr.eb(i);
            }
        }
        dp[0][0][0][0]=1;
        for(ll i=0;i<n;i++)
        {
            for(ll k=0;k<n;k++)
            for(ll j=0;j<11;j++)
            for(ll j1=0;j1<11;j1++)
            {
                dp[i+1][k+1][(j+arr[i+1])%11][j1]|=dp[i][k][j][j1];
                dp[i+1][k][j][(j1+arr[i+1])%11]|=dp[i][k][j][j1];
            }
        }
        ll helo=0;
        for(ll o=0;o<11;o++)
        {
            helo|=dp[n][n/2][o][o];
        }
        if(helo==1)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        cout<<"\n";
    }
    return 0;
}


//252908XL