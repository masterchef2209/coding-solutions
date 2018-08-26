#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long conc[n];
		for(int i=0;i<n;i++)
		{
			cin>>conc[i];
		}
		sort(conc,conc+n,greater<int>());
		double ans=(conc[0]+conc[1])/2;
		for(int i=2;i<n;i++)
		{
			ans=(ans+conc[i])/2;
		}
		cout<<fixed<<setprecision(8)<<ans<<endl;
	}
return 0;
}