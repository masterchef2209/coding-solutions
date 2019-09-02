        /*Read the problem carefully before starting to work on it*/
        
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (ll i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

#define int long long


// ll nCr[1005][1005];

// void precompute() 
// { 
//      for(int i=0;i<=1001;i++)
//      {
//          for(int j=0;j<=1001;j++)
//          {
//              nCr[i][j]=0;
//          }
//      }
//      for(int i=0;i<=1001;i++)
//      {
//          nCr[i][0]=1;
//      }
//      for(int i=1;i<=1001;i++)
//      {
//          for(int j=1;j<=i;j++)
//          {
//              nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%mod;
//          }
//      }
// } 



// vector<ll>factorso;
// vector<ll>factorse;

// ll evenf=0;
// ll oddf=0;

// void find_factors(ll num)
// {
//     //factorso.clear();
//     //factorse.clear();
//     evenf=0;
//     oddf=0;
//     for(ll i=1;i*i<=num;i++)
//     {
//         if(num%i==0)
//         {
//           // cout<<i<<" ";
//             if(i&1)
//                 oddf++;
//             else
//                 evenf++;
//             if(i!=(num/i))
//             {
//               // cout<<(num/i)<<" ";
//                 if((num/i)&1)
//                     oddf++;
//                 else
//                     evenf++;
//             }
//         }
//     }
// }

bool isprime(ll n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

bool check(ll num)
{
    if(num==1 || num==4)
        return true;
    else if(num&1)
    {
        return isprime(num);
    }
    else if(num%4==0)
    {
        return isprime(num/4);
    }
    else
    {
        return true;
    }
}

//vector<ll>frick;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
  //  precompute();
    for(ll test=1;test<=t;test++)
    {
        cout<<"Case #"<<test<<": ";
        ll l,r;
        cin>>l>>r;
        ll ans=0;
        for(ll i=l;i<=r;i++)
        {
            // if(i&1)
            // {
            //     ll ssize=factorso.size();
            //     ans+=(1+ssize+(ssize*(ssize-1))/2);
            // }
            // else
            // {
            //     ll sie=factorse.size();
            //     ll sio=factorso.size();
            //     if(sio==0)
            //     {
            //         ans+=(1+sie+(sie*(sie-1))/2);
            //         continue;
            //     }
            //     if(sie>sio)
            //         swap(sie,sio);
            //     for(ll x=0;x<=sie;x++)
            //     {
            //         ll val=0;
            //         ll val1=ncr(sie,x);
            //         for(ll y=max(0LL,x-2);y<=min(x+2,sio);y++)
            //         {
            //             val+=ncr(sio,y);
            //         }
            //         val1*=val;
            //         ans+=val1;
            //     }
            // }
            //find_factors(i);
            //ll a=factorse.size();
            //ll b=factorso.size();
            // ll a=evenf;
            // ll b=oddf;
            // ll c=abs(a-b);
            if(check(i))
            {
                ans++;
                //cout<<" YES\n";
                //frick.eb(i);
            }
           // else
            // {
            //     //cout<<" NO"<<endl;
                
            // }
        }
        cout<<ans;
        // for(auto &x:frick)
        // {
        //     cout<<x<<" ";
        // }
        cout<<"\n";
    }
    return 0;
}


//252908XL