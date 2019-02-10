#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],d[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>d[i];
		vector<int>bag;
		for(int i=0;i<n;i++)
		{
			int j,k;
			if(i==0)
				j=n-1;
			else
				j=i-1;
			k=(i+1)%n;
			if(d[i]>(a[j]+a[k]))
			{
				bag.emplace_back(i);
			}
		}
		int ans=-1;
		for(auto &c:bag)
		{
			ans=max(ans,d[c]);
		}
		cout<<ans<<endl;
	}
return 0;
}