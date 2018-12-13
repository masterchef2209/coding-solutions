#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n)
	{
		vector<int> vv(n);
		for(int i=0;i<n;i++)
		{
			cin>>vv[i];
		}
		sort(vv.begin(),vv.end());
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				vector<int>::iterator it=upper_bound(vv.begin(),vv.end(),vv[i]+vv[j]);
				if(it!=vv.end())
				{
					ans+=(vv.end()-it);
				}
			}
		}
		cout<<ans<<endl;
	cin>>n;
	}
return 0;
}