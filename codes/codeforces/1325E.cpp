/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
typedef int ll;
 
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
 
double PI=3.1415926535897932384626;
 
//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
 
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
 
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)
 
//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = 
//            chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};
 
#define fi first
#define se second
 
#define SSIZE 1000006
 
ll n;
 
bool isPrime(int n) 
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
 
set<ll> adj[SSIZE];
 
vector<ll> normalize(ll num)
{
	vector<ll>ret;
	for(ll i=2;i*i<=num;i++)
	{
	    ll zz=0;
		while(num%i==0)
		{
			zz++;
			num/=i;
		}
		if(zz&1)
		    ret.eb(i);
	}
	if(num>1)
	    ret.eb(num);
	return ret;
}
 
ll findcycle(ll node)
{
    if(adj[node].empty())
        return INT_MAX;
	ll ret=INT_MAX;
	vector<ll>visited(SSIZE,0);
	vector<ll>dist1(SSIZE,0);
	queue< pair<ll,ll> >Q;
	queue<ll>par;
	visited[node]=1;
	Q.push(mp(node,0));
	par.push(-1);
	while(!Q.empty())
	{
		ll curr=Q.front().fi;
		ll dist=Q.front().se;
		ll pp=par.front();
		par.pop();
		Q.pop();
		for(auto &nei:adj[curr])
		{
			if(!visited[nei])
			{
				visited[nei]=1;
				Q.push(mp(nei,dist+1));
				par.push(curr);
				dist1[nei]=dist+1;
			}
			else
			{
			    if(pp!=nei)
			    {
				    ret=min(ret,dist1[nei]+dist+1);
				    return ret;
			    }
			}
		}
	}
	return ret;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<ll>arr(n,0);
    for(ll i=0;i<n;i++)
	    cin>>arr[i];
	ll fl=-1;
	for(ll i=0;i<n;i++)
	{
		ll x;
		x=arr[i];
		vector<ll>fac=normalize(x);
		if(fac.size()==0)
		{
			cout<<1;
			return 0;
		}	
		if(fac.size()==1)
		{
			fac.eb(1);
		}
		//cout<<fac[0]<<" "<<fac[1]<<endl;
		if(adj[fac[0]].find(fac[1])!=adj[fac[0]].end())
		{
		    fl=1;
		}
		adj[fac[0]].insert(fac[1]);
		adj[fac[1]].insert(fac[0]);
	}
	if(fl==1)
	{
	    cout<<2;
	    return 0;
	}
	vector<ll>sourc;
	sourc.eb(1);
	for(ll i=1;i<=1000;i++)
	{
		if(isPrime(i))
		{
			sourc.eb(i);
		}
	}
	ll ans=INT_MAX;
	for(auto &ss:sourc)
	{
		ll val=findcycle(ss);
		ans=min(ans,val);
	}
	if(ans==INT_MAX)
		cout<<-1;
	else
		cout<<ans;
    return 0;
}
 
 
//252908XL