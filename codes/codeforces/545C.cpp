#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		int x,h;
		cin>>x>>h;
		cout<<1;
		return 0;
	}
	vector<int>xx,hh;
	for(int i=0;i<n;i++)
	{
		int x,h;
		cin>>x>>h;
		xx.emplace_back(x);
		hh.emplace_back(h);
	}
	int ans=2;
	for(int i=1;i<n-1;i++)
	{
		if(hh[i]<=xx[i]-xx[i-1]-1)
		{
			ans++;
		}
		else if(hh[i]<=xx[i+1]-xx[i]-1)
		{
			ans++;
			xx[i]+=hh[i];
		}
	}
	cout<<ans;
return 0;
}