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
		int k;
		cin>>k;
		string s;
		cin>>s;
		long long ans=LLONG_MIN;
		for(int i=0;i<n-k;i++)
		{
			long long pro=1;
			for(int j=i;j<i+k;j++)
			{
				pro*=(s[j]-'0');
			}
			if(pro>ans)
			{
				ans=pro;
			}
		}
		cout<<ans<<endl;
	}
return 0;
}