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
    	string s;
    	cin>>s;
    	if(s=="0")
    	{
    	   cout<<0;
    	   return 0;
    	}
    	reverse(s.begin(),s.end());
    	ll c=0,c1=0;
    	ll ans=0;
    	for(ll i=0;i<s.size();i++)
    	{
    	    if(s[i]=='1')
    		{
    		  c++;
    		}
    	}
    	for(ll i=0;i<s.size();i+=2)
    	{
    	    if(s[i]=='1')
    		{
    		  c1++;
    		}
    		ans++;
    	}
    	if(c==1 && c1==1)
    		ans--;
    	cout<<ans;
        return 0;
    }
     
     
    //252908XL