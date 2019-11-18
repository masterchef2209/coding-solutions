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
 
#define SSIZE 500020
 
ll n,m;
ll t[22][SSIZE];
ll a[SSIZE];
ll lazy[22][SSIZE];
 
void push(ll v,ll i,ll tl,ll tr,ll tm)
{
    if(!lazy[i][v])
        return;
    lazy[i][v*2]^=1;
    lazy[i][v*2+1]^=1;
    t[i][v*2]=(tm-tl+1)-t[i][v*2];
    t[i][v*2+1]=(tr-(tm+1)+1)-t[i][v*2+1];
    lazy[i][v]=0;
}
 
void build(ll v,ll tl,ll tr,ll i)
{
    if(tl==tr)
    {
        t[i][v]=((a[tl]>>i)&1LL);
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(v*2,tl,tm,i);
        build(v*2+1,tm+1,tr,i);
        t[i][v]=t[i][v*2]+t[i][v*2+1];
    }
}
 
void update(ll v,ll tl,ll tr,ll l,ll r,ll i)
{
    if(tl>=l && tr<=r)
    {
        t[i][v]=(tr-tl+1)-t[i][v];
        lazy[i][v]^=1;
        return;
    }
    if(tr<l || tl>r)
        return;

        ll tm=(tl+tr)/2;
        push(v,i,tl,tr,tm);
        update(v*2,tl,tm,l,r,i);
        update(v*2+1,tm+1,tr,l,r,i);
        t[i][v]=t[i][v*2]+t[i][v*2+1];
}
 
ll query(ll v,ll tl,ll tr,ll l,ll r,ll i)
{
        if(tl>=l &&tr<=r)
    {
        return t[i][v];
    }
    if(tr<l || tl>r)
        return 0;

        ll tm=(tl+tr)/2;
        push(v,i,tl,tr,tm);
        return ( query(v*2,tl,tm,l,r,i)+query(v*2+1,tm+1,tr,l,r,i) );

}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(ll i=0;i<=21;i++)
        build(1,0,n-1,i);
    while(m--)
    {
        ll st;
        cin>>st;
        if(st==1)
        {
            ll l,r;
            cin>>l>>r;
            ll pp=0;
            for(ll i=0;i<=21;i++)
            {
                pp+=(query(1,0,n-1,l-1,r-1,i) * (1LL<<i) );
            }
            cout<<pp<<"\n";
        }
        else if(st==2)
        {
            ll l,r,x;
            cin>>l>>r>>x;
            for(ll i=0;i<=21;i++)
                if(x&(1LL<<i))
                update(1,0,n-1,l-1,r-1,i);
        }
    }
    return 0;
}
 
 
//252908XL