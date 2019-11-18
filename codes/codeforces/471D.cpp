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

#define SSIZE 200005
#define int long long

ll n,w;

vector<ll>N(SSIZE);
vector<ll>W(SSIZE);

vector<int> prefix_function(vector<int> &v) 
{
	int n = (int)v.size();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && v[i] != v[j])
			j = pi[j-1];
		if (v[i] == v[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> find_occurences(vector<int> &text, vector<int> &pattern)
{
	vector<int> v=pattern;
	v.push_back(LLONG_MIN);
	for(auto &it:text)
		v.push_back(it);
	int sz1=text.size(), sz2=pattern.size();
	vector<int> lps=prefix_function(v);
	vector<int> store;
	for(int i=sz2+1;i<=sz1+sz2;i++)
	{
		if(lps[i]==sz2)
			store.push_back(i-sz2*2);
	}
	return store;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>w;
	for(ll i=0;i<n;i++)
		cin>>N[i];
	for(ll j=0;j<w;j++)
		cin>>W[j];
	if(w>n)
	{
		cout<<0;
	}
	else
	{
		if(w==1)
		{
			cout<<n;
		}
		else
		{
			vector<ll>hay,needle;
			for(ll i=0;i<(n-1);i++)
				hay.eb(N[i]-N[i+1]);
			for(ll i=0;i<(w-1);i++)
				needle.eb(W[i]-W[i+1]);
			vector<ll>ans=find_occurences(hay,needle);
			
			
			cout<<(ans.size());
		}
	}
    return 0;
}


//252908XL