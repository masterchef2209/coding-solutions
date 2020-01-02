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
	string s(300,'a');
	cout<<s<<endl;
	ll counta;
	cin>>counta;
	if(counta==0)
	    return 0;
	counta=300-counta;
	string s1(300,'b');
	cout<<s1<<endl;
	ll countb;
	cin>>countb;
	countb=300-countb;
	ll sum=counta+countb;
	if(countb==0)
	{
	    string alol(counta,'a');
	    cout<<alol<<endl;
	    ll alol1;
	    cin>>alol1;
	    return 0;
	}
	if(counta==0)
	{
	    string lol(countb,'b');
	    cout<<lol<<endl;
	    ll lol1;
	    cin>>lol1;
	    return 0;
	}
	string s2(sum,'b');
	ll yu=0;
	for(ll i=0;i<sum;i++)
	{
		s2[i]='a';
		cout<<s2<<endl;
		ll num;
		cin>>num;
		if(num==0)
		    break;
		if(num==(counta-1-yu) )
		{
			yu++;
		}
		else
		{
			s2[i]='b';
		}
	}
    return 0;
}


//252908XL
