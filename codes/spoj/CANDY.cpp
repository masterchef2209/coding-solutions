#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=-1)
	{
		int arr[n];
		int s=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			s+=arr[i];
		}
		if(s%n!=0)
			cout<<-1<<endl;
		else
		{
			s=s/n;
			int temp=0;
			for(int i=0;i<n;i++)
			{
				if(arr[i]-s>0)
					temp+=(arr[i]-s);
			}
			cout<<temp<<endl;
		}
		cin>>n;
	}
return 0;
}