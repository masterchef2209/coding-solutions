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
 
set<ll>ss;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>arr(n);
    map<ll,ll>mm;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        mm[arr[i]]++;
    }
    sort(arr.begin(),arr.end());
    ll meme=0,mama=0;
    for(ll val=1;val<=n;val++)
    {
        // val exists so we group (val,val+1,val+2) and ignore the existence of val+1,val+2
        if(mm[val])
        {
            meme++;
            val+=2;
        }
    }
    for(ll i=0;i<n;)
    {
        if(mm[arr[i]]==1)
        {
            ll hehe=0;
            if(ss.find(arr[i]-1)==ss.end())
            {
                ss.insert(arr[i]-1);
                hehe++;
            }
            if(ss.find(arr[i])==ss.end())
            {
                if(hehe==1)
                {
                    i++;
                    continue;
                }
                ss.insert(arr[i]);
                hehe++;
            }
            if(ss.find(arr[i]+1)==ss.end())
            {
                if(hehe==1)
                {
                    i++;
                    continue;
                }
                ss.insert(arr[i]+1);
                hehe++;
            }
            i++;
            continue;
        }
        else if(mm[arr[i]]==2)
        {
            ll hehe=0;
            if(ss.find(arr[i]-1)==ss.end())
            {
                ss.insert(arr[i]-1);
                hehe++;
            }
            if(ss.find(arr[i])==ss.end())
            {
                ss.insert(arr[i]);
                hehe++;
            }
            if(ss.find(arr[i]+1)==ss.end())
            {
                if(hehe==2)
                {
                    i+=2;
                    continue;
                }
                ss.insert(arr[i]+1);
                hehe++;
            }
            i+=2;
            continue;
        }
        else
        {
            ll hehe=0;
            if(ss.find(arr[i]-1)==ss.end())
            {
                ss.insert(arr[i]-1);
            }
            if(ss.find(arr[i])==ss.end())
            {
                ss.insert(arr[i]);
            }
            if(ss.find(arr[i]+1)==ss.end())
            {
                ss.insert(arr[i]+1);
            }
            ll lol=arr[i];
            while(i<n && arr[i]==lol)
                i++;
            continue;
        }
    }
    cout<<meme<<" "<<ss.size();
    return 0;
}
 
 
//252908XL