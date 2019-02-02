#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,d;
	cin>>n>>d;
	pair<int,int> fr[n];
	for(int i=0;i<n;i++)
	{
		cin>>fr[i].first>>fr[i].second;
	}
	sort(fr,fr+n);
	int ans=fr[0].second,sum=fr[0].second;
	int i=1,j=0;
	while(i<n)
	{
		while(j<i && fr[i].first-fr[j].first>=d)
		{
			sum-=fr[j].second;
			j++;
		}
		if(fr[i].first-fr[j].first<d)
		{
			sum+=fr[i].second;
		}
		ans=max(ans,sum);
		i++;
	}
	cout<<ans<<endl;
return 0;
}