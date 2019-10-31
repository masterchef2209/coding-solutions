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
 
vector<ll>arr;
stack<ll>st;
string ans("");

stack<ll>st1;
string ans1("");
 
void f(ll i,ll j)
{
    if(i>j)
        return;
    if(!st.empty())
    {
        ll prev=st.top();
        
        if(arr[i]==arr[j])
        {
            //cout<<i<<" "<<j<<endl;
            if(arr[i]<=prev)
                return;
            ans.pb('R');
            st.push(arr[j]);
            f(i,j-1);
        }
        else if(arr[i]<arr[j])
        {
            if(arr[i]<=prev)
            {
                if(arr[j]<=prev)
                    return;
                else
                {
                    ans.pb('R');
                    st.push(arr[j]);
                    f(i,j-1);
                }
            }
            else
            {
                ans.pb('L');
                st.push(arr[i]);
                f(i+1,j);
            }
        }
        else
        {
            if(arr[j]<=prev)
            {
                if(arr[i]<=prev)
                    return;
                else
                {
                     ans.pb('L');
                    st.push(arr[i]);
                    f(i+1,j);
                }
            }
            else
            {
                ans.pb('R');
                st.push(arr[j]);
                f(i,j-1);
            }
        }
    }
    else
    {
        if(arr[i]==arr[j])
        {
           // cout<<i<<" "<<j<<endl;
            ans.pb('R');
            st.push(arr[j]);
            f(i,j-1);
        }
        else if(arr[i]<arr[j])
        {
            ans.pb('L');
            st.push(arr[i]);
            f(i+1,j);
        }
        else
        {
            ans.pb('R');
            st.push(arr[j]);
            f(i,j-1);
        }
    }
}
 
void f1(ll i,ll j)
{
    if(i>j)
        return;
    if(!st1.empty())
    {
        ll prev=st1.top();
        
        if(arr[i]==arr[j])
        {
           // cout<<i<<" "<<j<<endl;
            if(arr[i]<=prev)
                return;
            ans1.pb('L');
            st1.push(arr[i]);
            f1(i+1,j);
        }
        else if(arr[i]<arr[j])
        {
            if(arr[i]<=prev)
            {
                if(arr[j]<=prev)
                    return;
                else
                {
                    ans1.pb('R');
                    st1.push(arr[j]);
                    f1(i,j-1);
                }
            }
            else
            {
                ans1.pb('L');
                st1.push(arr[i]);
                f1(i+1,j);
            }
        }
        else
        {
            if(arr[j]<=prev)
            {
                if(arr[i]<=prev)
                    return;
                else
                {
                     ans1.pb('L');
                    st1.push(arr[i]);
                    f1(i+1,j);
                }
            }
            else
            {
                ans1.pb('R');
                st1.push(arr[j]);
                f1(i,j-1);
            }
        }
    }
    else
    {
        if(arr[i]==arr[j])
        {
            //cout<<i<<" "<<j<<endl;
            ans1.pb('L');
            st1.push(arr[i]);
            f1(i+1,j);
        }
        else if(arr[i]<arr[j])
        {
            ans1.pb('L');
            st1.push(arr[i]);
            f1(i+1,j);
        }
        else
        {
            ans1.pb('R');
            st1.push(arr[j]);
            f1(i,j-1);
        }
    }
} 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    for(ll u=0;u<n;u++)
    {
        ll tmp;
        cin>>tmp;
        arr.eb(tmp);
    }
    f(0,n-1);
    f1(0,n-1);

    if((ans.size())>=(ans1.size()))
    {
        cout<<ans.size()<<"\n";
        cout<<ans;
    }
    else
    {
        cout<<ans1.size()<<"\n";
        cout<<ans1;
    }
    return 0;
}
 
 
//252908XL