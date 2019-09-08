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

#define INF (1<<29)

#define WHITE 0
#define GRAY 1
#define BLACK 2

ll n;
ll ans;
vector<ll>c(SSIZE);
vector<ll>a(SSIZE);
vector<ll>visited(SSIZE,WHITE);

stack<ll>st;

void dfs(ll i)
{
    visited[i]=GRAY;
    st.push(i);
    if(visited[a[i]]==GRAY)
    {
        ll tem=INF;
        while(!st.empty())
        {
            ll tt=st.top();
            st.pop();
            tem=min(c[tt],tem);
            if(tt==a[i])
                break;
        }
        ans+=tem;
    }
    else if(visited[a[i]]==WHITE)
    {
        dfs(a[i]);
    }
    visited[i]=BLACK;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>c[i];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	ans=0;
	for(ll i=0;i<n;i++)
	{
		if(a[i]==(i))
		{
			visited[i]=BLACK;
			ans+=c[i];
		}
	}
	for(ll i=0;i<n;i++)
	{
		if(visited[i]==WHITE)
		{
			dfs(i);
		}
	}
	cout<<ans;
    return 0;
}


//252908XL