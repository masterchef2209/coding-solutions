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

#define SSIZE 50

ll n;

ll parent[SSIZE];
ll size[SSIZE];


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	set<char>bag;
	for(ll u=0;u<=27;u++)
		make_set(u);
	vector<string>data(n);
	for(ll u=0;u<n;u++)
	{
		cin>>data[u];
		for(ll j=0;j<data[u].size();j++)
		    bag.insert(data[u][j]);
		for(ll j=1;j<data[u].size();j++)
		{
		    if(find_set(data[u][j]-'a')!=find_set(data[u][j-1]-'a'))
		    {
		        union_sets(data[u][j]-'a',data[u][j-1]-'a');
		    }
		}
	}
	set<ll>lol;
	for(ll i=0;i<26;i++)
	{
		parent[i]=find_set(i);
	}
	for(ll i=0;i<26;i++)
	{
	    char hehe='a'+i;
	    if(bag.find(hehe)!=bag.end())
		    lol.insert(parent[i]);
	}
	cout<<(lol.size());
    return 0;
}


//252908XL