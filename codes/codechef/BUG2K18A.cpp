#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x=0,y=0;
		int n;
		cin>>n;
		long arr[n];
		long r;
		cin>>r;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			x++;
			if(arr[i]<=r)
			{
				y++;
			}
		}
		cout<<x<<" "<<y<<" "<<y<<endl;
	}
return 0;
}