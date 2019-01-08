#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,u;
		cin>>n>>u;
		long long arr[n];
		memset(arr,0,sizeof(arr));
		for(int i=0;i<u;i++)
		{
			long long l,r,val;
			cin>>l>>r>>val;
			arr[l]+=val;
			if(r<n-1)
				arr[r+1]-=val;
		}
		for(int i=1;i<n;i++)
		{
			arr[i]=arr[i]+arr[i-1];
		}
		int q;
		cin>>q;
		while(q--)
		{
		    int temp;
		    cin>>temp;
		    cout<<arr[temp]<<endl;
		}
	}
return 0;
}