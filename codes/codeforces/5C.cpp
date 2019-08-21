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

#define SIZE 1000006

ll d[SIZE];
ll c[SIZE];

stack<ll>st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			st.push(i);
		}
		else
		{
			if(st.empty())
			{
				d[i]=-1;
				c[i]=-1;
			}
			else
			{
				d[i]=st.top();
				c[i]=d[i];
				st.pop();
				if(d[i]>0)
				{
					if(s[d[i]-1]==')' && c[d[i]-1]!=-1)
					{
						c[i]=c[d[i]-1];
					}
				}
			}
		}
	}
	map<ll,ll>mm;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]==')')
		{
			if(c[i]!=-1)
			{
				mm[i-c[i]+1]++;
			}
		}
	}
	if(mm.empty())
	{
		cout<<0<<" "<<1;
	}
	else
	{
		cout<< (mm.rbegin())->fi<<" "<<(mm.rbegin())->se;
	}
    return 0;
}


//252908XL