		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k;

vector<ll>arr(18);

ll dp[(1<<18)][18];
ll cc[18][18];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int u=0;u<k;u++)
	{
		int x,y;
		ll c;
		cin>>x>>y>>c;
		x--;
		y--;
		cc[x][y]=c;
	}
	ll ans=0;
	for(int mask=1;mask<(1<<n);mask++)
	{
		int co=__builtin_popcount(mask);
		if(co>m)
			continue;
 		for(int j=0;j<n;j++)
		{
		    dp[mask][j]=-1e18;
			if(!(mask>>j &1))
			    continue;
			for(int k=0;k<n;k++)
				if(mask>>k & 1)
					dp[mask][j]=max(dp[mask][j],arr[j]+dp[(mask^(1<<j))][k]+cc[k][j]);
			if(co==m)
	           ans=max(ans,dp[mask][j]);	
		}
	}
	cout<<ans;
    return 0;
}