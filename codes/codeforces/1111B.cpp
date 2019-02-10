#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,m;
	cin>>n>>k>>m;
	int arr[n+1],prefix[n+1];
	arr[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n,greater<int>());
	prefix[0]=0;
	for(int i=1;i<=n;i++)
	{
		prefix[i]=arr[i]+prefix[i-1];
	}
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		if(n-i>m)
			continue;
		int rem=m-(n-i);
		double sum=min(k*i,rem);
		sum+=prefix[i];
		ans=max(ans,sum/i);
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
return 0;
}