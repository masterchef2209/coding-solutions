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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll num[10]={0};
	for(ll i=0;i<s.size();i++)
	{
		num[s[i]-'0']=1;
	}
	ll row[4]={0},col[4]={0};
    if(num[1]||num[2]||num[3])
        row[1]=1;
    if(num[4]||num[5]||num[6])
        row[2]=1;
    if(num[7]||num[8]||num[9])
        row[3]=1;
    if(num[1]||num[4]||num[7])
        col[1]=1;
    if(num[2]||num[5]||num[8])
        col[2]=1;
    if(num[3]||num[6]||num[9])
        col[3]=1;
    if(num[1] && num[9])
    {
        cout<<"YES";
    }
    else if(num[3] && num[7])
    {
        cout<<"YES";
    }
    else if(row[1] && num[0])
    {
        cout<<"YES";
    }
    else if(num[1] && num[6] && (num[7]||num[9]))
    {
        cout<<"YES";
    }
    else if(num[3] && num[4] && (num[7]||num[9]))
    {
        cout<<"YES";
    }
    else if(num[9] && num[4] && row[1])
    {
        cout<<"YES";
    }
    else if(num[7] && num[6] && row[1])
    {
        cout<<"YES";
    }
    else if(num[2] && num[9] && col[1])
    {
        cout<<"YES";
    }
    else if(num[7] && num[2] && col[3])
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}


//252908XL