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

bool check(string &w)
{
    string v=w;
    reverse(v.begin(),v.end());
    return (v==w);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<string>bag;
	set<ll>av;
	for(ll i=0;i<n;i++)
	{
		av.insert(i);
		string ss;
		cin>>ss;
		bag.eb(ss);		
	}
	string pre("");
	string suf("");
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			string x=bag[i];
			string y=bag[j];
			reverse(y.begin(),y.end());
			if(x==y)
			{
			    reverse(y.begin(),y.end());
				pre=pre+x;
				suf=y+suf;
				av.erase(av.find(i));
				av.erase(av.find(j));
			}
		}
	}
	string centre("");
	for(auto &lol:av)
	{
		string z=bag[lol];
		if(check(z))
		{
			centre=z;
			break;
		}
	}
	if(centre=="")
	{
		pre+=suf;
		cout<<(pre.size())<<endl;
		cout<<pre<<endl;
		return 0;
	}
		pre+=centre;
		pre+=suf;
		cout<<(pre.size())<<endl;
		cout<<pre<<endl;
    return 0;
}


//252908XL