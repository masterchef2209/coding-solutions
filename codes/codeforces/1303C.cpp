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

vector< set<char> >data(26);
string ans;
ll visited[26]={0};

void dfs(ll curr)
{
	visited[curr]=1;
	ans+=(char)('a'+curr);
	for(auto &nei:data[curr])
	{
		if(!visited[nei-'a'])
			dfs(nei-'a');
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		for(ll i=0;i<26;i++)
		{
			data[i].clear();
		}
		string s;
		cin>>s;
		for(ll i=0;i<s.size();i++)
		{
			if((i+1)<s.size())
				data[s[i]-'a'].insert(s[i+1]);
			if((i-1)>=0)
				data[s[i]-'a'].insert(s[i-1]);
		}
		ll fl=0,hehe=0;
		for(ll lol=0;lol<26;lol++)
		{
			if(data[lol].size()>2)
			{
				fl=1;
				break;
			}
			if(data[lol].size()<2)
				hehe++;
		}
		if(hehe<2)
		{
			fl=1;
		}
		if(fl)
		{
			cout<<"NO\n";
		}
		else
		{
			ans="";
			for(ll i=0;i<26;i++)
				visited[i]=0;
			vector<ll>st;
			for(ll i=0;i<26;i++)
			{
				if(data[i].empty())
				{
					ans+=(char)('a'+i);
					visited[i]=1;
				}
				if(data[i].size()==1)
				{
					st.eb(i);
				}
			}
			for(ll i=0;i<st.size();i++)
			{
				if(!visited[st[i]])
				{
					dfs(st[i]);
				}
			}
			if(ans.size()!=26)
			    cout<<"NO\n";
			else
			{
			    cout<<"YES\n";
			    cout<<ans<<endl;
			}
		}
	}
    return 0;
}


//252908XL