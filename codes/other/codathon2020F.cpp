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

int dp[100005],dp_left[100005],dp_right[100005],p[100005];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,i,j,k,q,l,r;
    string a;
    char x,y;
    sd(n);
    p[0]=1;
    for(i=1;i<=n;i++)
        p[i]=(1ll*p[i-1]*2)%mod;
    cin>>a;
    x=getchar();
    x=getchar();
    y=getchar();
    y=getchar();
    int ans=0;
    j=0;
    for(i=0;i<n;i++)
    {
        k=j;
        if(a[i]==x)
            j+=1;
        if(a[i]==y)
        {
            ans+=j;
            if(ans>=mod)
                ans-=mod;
        }
        j+=k;
        if(j>=mod)
            j-=mod;
        dp_left[i+1]=j;
        dp[i+1]=ans;
    }
    j=0;
    for(i=n-1;i>=0;i--)
    {
        k=j;
        if(a[i]==y)
            j+=1;
        j+=k;
        if(j>=mod)
            j-=mod;
        dp_right[i+1]=j;
    }
    q=1;
    while(q--)
    {
        l=0;
        r=n-1;
        l++;
        r++;
        ans=dp[r]-dp[l-1];
        if(ans<0)
            ans+=mod;
        j=(1ll*dp_right[r+1]*p[r-l+1])%mod;
        j=dp_right[l]-j;
        if(j<0)
            j+=mod;
        j=(1ll*dp_left[l-1]*j)%mod;
        ans-=j;
        if(ans<0)
            ans+=mod;
        printf("%d\n",ans);
    }
    return 0;
}

//252908XL