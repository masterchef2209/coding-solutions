		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

ll arr[100005][26];
ll hehe[26][26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	ll ans=0;
	map<char,ll>mm;
	for(ll i=0;i<s.size();i++)
	{
	    mm[s[i]]++;
	    ans=max(ans,mm[s[i]]);
	}
	for(ll i=0;i<s.size();i++)
	{
	    arr[i][s[i]-'a']=1;
	}
	for(ll i=1;i<s.size();i++)
	{
	    for(ll j=0;j<26;j++)
	    {
	        arr[i][j]+=arr[i-1][j];
	    }
	}
	for(ll i=1;i<s.size();i++)
	{
        for(ll j=0;j<26;j++)
        {
            ll val=arr[i-1][j];
            hehe[j][s[i]-'a']+=val;
        }
	}
	for(ll i=0;i<26;i++)
	for(ll j=0;j<26;j++)
	{
	    ans=max(ans,hehe[i][j]);
	}
	cout<<ans;
    return 0;
}


//252908XL