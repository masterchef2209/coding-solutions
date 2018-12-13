#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	long long arr[n+1];
	map<int,int> mm;
	memset(arr,0,sizeof(arr));
	while(q--)
	{
		int a;
		cin>>a;
		if(a==1)
		{
			int j,i;
			cin>>j>>i;
			long long temp=arr[j]^(1LL<<(i-1));
			long long temp1=temp&(1LL<<(i-1));
			if(temp1==0)
			{
				mm[j]--;
			}
			else
			{
				mm[j]++;
			}
			arr[j]=temp;
		}
		else if(a==2)
		{
			int l,r;
			int count=0;
			cin>>l>>r;
      // map<int,int>::iterator it=mm.begin();
      // for(int i=1;i<=n;i++)
      // {
      //   cout<<arr[i]<<endl;
      // }
      // while(it!=mm.end())
      // {
      //   cout<<it->first<<" "<<it->second<<endl;
      // }
			int ans=0;
			map<int,int>::iterator it=mm.lower_bound(l);
			while(it!=mm.end() && it->first<=r)
			{
				int abc=it->second;
				if(abc==3)
				{
					count++;
				}
				else
				{
					if(count>ans)
						ans=count;
					count=0;
				}
				it++;
			}
      if(count>ans)
				ans=count;
			count=0;
			cout<<ans<<endl;
		}
	}
return 0;
}