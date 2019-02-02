#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005

int n,m,k;
int s[N],t[N],d[N],w[N],dp[N][205];
vector< pair<int,int> >events[N];
multiset< pair<int,int> >curr;

int nxt[N],val[N];

int func(int i,int alice)
{
	if(alice<0)
	{
		return LLONG_MAX;
	}
	if(i>n)
		return 0;
	if(dp[i][alice]!=-1)
		return dp[i][alice];
	// dp = either alex uses her power(func(i+1,alice-1)) or she doesn't so value will be added (value+func(next,alice))
	return dp[i][alice]=min(val[i]+func(nxt[i],alice),func(i+1,alice-1));
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>s[i]>>t[i]>>d[i]>>w[i];
		events[s[i]].push_back({w[i],d[i]});
		events[t[i]+1].push_back({-w[i],d[i]});
	}
	for(int i=1;i<=n;i++)
	{
		for(auto &x:events[i])
		{
			if(x.first>=0)
			{
				curr.insert(x);
			}
			else
			{
				curr.erase(curr.find({-x.first,x.second}));
			}
		}
		if(curr.empty())
		{
			val[i]=0;
			nxt[i]=i+1;
			continue;
		}
		pair<int,int> pp= *(--curr.end()); //best value
		val[i]=pp.first;
		nxt[i]=pp.second+1;
	}
	int ans=func(1,m);
	cout<<ans;
return 0;
}