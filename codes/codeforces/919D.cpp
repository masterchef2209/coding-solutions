#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
#define int long long
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define f first
#define s second

vector< set<int> >adj(300005);
vi visited(300005,0);
vector<char>value(300005);
vi onstack(300005,0);
vi indegree(300005,0);
vector< vi >dp(300005,vi(26,0));
int ans=LLONG_MIN;

int cycle=0;

void dfs(int i)
{
    if(cycle==1)
        return;
    if(*max_element(dp[i].begin(),dp[i].end())>0)
        return;
	visited[i]=1;
	onstack[i]=1;
	for(auto &x:adj[i])
	{
	    if(cycle==1)
	        return;
		if(visited[x])
		{
			if(onstack[x])
			{
				cycle=1;
				return;
			}
			else
			{
			    dfs(x);
			    for(int k=0;k<26;k++)
			    {
			        dp[i][k]=max(dp[i][k],dp[x][k]);
			    }
			}
		}
		else
		{
			dfs(x);
			for(int k=0;k<26;k++)
			{
			    dp[i][k]=max(dp[i][k],dp[x][k]);
			}
		}
	}
	dp[i][value[i]-'a']+=1;
	onstack[i]=0;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m;
	int selfloop=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char temp;
		cin>>temp;
		value[i]=temp;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].insert(b);
		indegree[b]++;
		if(a==b)
			selfloop=1;
	}
	if(selfloop==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(cycle==1)
			break;
		if(indegree[i]==0 && visited[i]==0)
		{
			dfs(i);
			ans=max(ans,*max_element(dp[i].begin(),dp[i].end()));
		}
	}
	if(cycle==1 || ans==LLONG_MIN)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
    return 0;
}