#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long arr[20][20];
	long long mm=LLONG_MIN;
	for(int i=0;i<20;i++)
	for(int j=0;j<20;j++)
	{
		cin>>arr[i][j];
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<=16;j++)
		{
			long long mul1=arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3];
			//cout<<arr[i][j]<<" "<<arr[i][j+1]<<" "<<arr[i][j+2]<<" "<<arr[i][j+3]<<endl;
			if(mul1>mm)
			{
				mm=mul1;
			}
			long long mul2=arr[j][i]*arr[j+1][i]*arr[j+2][i]*arr[j+3][i];
			//cout<<arr[j][i]<<" "<<arr[j+1][i]<<" "<<arr[j+2][i]<<" "<<arr[j+3][i]<<endl;
			if(mul2>mm)
			{
				mm=mul2;
			}
		}
	}
	for(int i=0;i<=16;i++)
	{
		for(int j=0;j<=16;j++)
		{
			long long mul1=arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3];
			//cout<<arr[i][j]<<" "<<arr[i+1][j+1]<<" "<<arr[i+2][j+2]<<" "<<arr[i+3][j+3]<<endl;
			if(mul1>mm)
			{
				mm=mul1;
			}
			long long mul2=arr[i][19-j]*arr[i+1][19-j-1]*arr[i+2][19-j-2]*arr[i+3][19-j-3];
			//cout<<arr[i][19-j]<<" "<<arr[i+1][19-j-1]<<" "<<arr[i+2][19-j-2]<<" "<<arr[i+3][19-j-3]<<endl;
			if(mul2>mm)
			{
				mm=mul2;
			}
		}
	}
	cout<<mm<<endl;
	
return 0;
}
