#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k1,k2,k3;
		scanf("%d %d %d %d",&n,&k1,&k2,&k3);
		int arr[n],prefix[n];
		multiset<int>ms;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			if(i==0)
				prefix[i]=arr[i];
			else
			{
				prefix[i]=prefix[i-1]+arr[i];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				int temp;
				if(i==0)
				{
					temp=(prefix[j]);
				}
				else
				{
					temp=(prefix[j]-prefix[i-1]);
				}
				if(ms.size()<k3)
				{
					ms.insert(temp);
				}
				else
				{
					if( (*ms.begin())<temp )
					{
						ms.erase(ms.begin());
					 	ms.insert(temp);
					}
				}
			}
		}
		vector<int>ans(ms.rbegin(),ms.rend());
		cout<<ans[k1-1]<<" "<<ans[k2-1]<<" "<<ans[k3-1]<<endl;
	}
return 0;
}