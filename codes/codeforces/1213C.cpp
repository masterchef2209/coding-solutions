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

vector< vector<ll> >arr(10);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll sum[10]={0};
	for(ll i=0;i<=9;i++)
	{
	    ll visited[10]={0};
		for(ll j=i;;j+=i)
		{
			if(visited[j%10])
				break;
			arr[i].eb(j%10);
			sum[i]+=(j%10);
			visited[j%10]=1;
		}
	}
// 	for(ll i=0;i<=9;i++)
//  	{
//  	    cout<<sum[i]<<" "<<endl;
// 	    for(auto &x:arr[i])
// 	    {
// 	           cout<<x<<" ";
// 	    }
// 	    cout<<endl;
//  	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll n,m;
		cin>>n>>m;
		ll dig=m%10;
		ll num=arr[dig].size();
		ll tem1=n/m;
		//cout<<tem1<<endl;
		ll tem=tem1/num;
		//cout<<tem<<endl;
		ll rem=tem1%num;
		ll ans=sum[dig]*tem;
		//cout<<num<<endl;
		rem=min(rem,num);
		for(ll i=0;i<rem;i++)
		{
		    ans+=arr[dig][i];
		}
		cout<<ans<<"\n";
		
	}
    return 0;
}


//252908XL