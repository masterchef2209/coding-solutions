#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	int mm=INT_MAX;
	for(int x=1;x<=n;x++)
	{
		int sum=0;
		for(int y=1;y<=n;y++)
		{
			sum+=(v[y]*(2*abs(y-x)+2*abs(y-1)+2*abs(x-1)));
      //cout<<sum<<endl;
		}
		//cout<<sum<<endl;
		if(sum<mm)
		{
			mm=sum;
		}
	}
	cout<<mm;
return 0;
}