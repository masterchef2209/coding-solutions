#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n;
	cin>>n;
	int arr[2*n],prefix[2*n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[i+n]=arr[i];	
	}
	prefix[0]=arr[0];
	for(int j=1;j<2*n;j++)
	{
		prefix[j]=prefix[j-1]+arr[j];
	}
	n*=2;
	int s,f;
	cin>>s>>f;
	int len=f-s;
	int sum=0,out=0;
	for(int i=1;i<n-len+1;i++)
	{
		int x=(s-i+n+n)%(n/2);
		if(x==0)	x=n/2;
		if(prefix[i+len-1]-prefix[i-1]>sum || (prefix[i+len-1]-prefix[i-1]==sum && x<out))
		{
			sum=prefix[i+len-1]-prefix[i-1];
			out=x;
		} 
	}
	cout<<out<<endl;
return 0;
}