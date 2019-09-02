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

ll n;
string one,two;

bool check(string &s)
{
	for(ll i=0;i<(s.size()-1);i++)
	{
		if(s[i]==one[0] && s[i+1]==one[1])
			return true;
		if(s[i]==two[0] && s[i+1]==two[1])
			return true;
	}
return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>one>>two;
	cout<<"YES\n";
	string sample="abc";
	do
	{
		string tem1=string(n,sample[0])+string(n,sample[1])+string(n,sample[2]);
		if(!check(tem1))
		{
			cout<<tem1;
			return 0;
		}
		ll hehe=n;
		string tem2("");
		while(hehe--)
		{
			tem2+=sample;
		}
		if(!check(tem2))
		{
			cout<<tem2;
			return 0;
		}
	}while(next_permutation(sample.begin(),sample.end()));
    return 0;
}


//252908XL