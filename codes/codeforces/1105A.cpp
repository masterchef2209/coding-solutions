#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		arr.emplace_back(p);
	}
	int anst=-1;
	int ansum=INT_MAX;
	for(int k=1;k<=100;k++)
	{
		int sum=0;
		for(int j=0;j<arr.size();j++)
		{
			if((arr[j]-k)>1)
			{
				sum+=(arr[j]-k)-1;
			}
			else if((k-arr[j])>1)
			{
				sum+=(k-arr[j])-1;
			}
		}
		if(sum<ansum)
		{
			ansum=sum;
			anst=k;
		}
	}
	cout<<anst<<" "<<ansum;
return 0;
}