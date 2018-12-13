#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(!(n&1))
	{
		cout<<-1;
		exit(0);
	}
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=i;
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<(arr[i]+arr[i])%n<<" ";
	}
return 0;
}