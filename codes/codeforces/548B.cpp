#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	int arr[n][m];
	int arr1[n];
	for(int i=0;i<n;i++)
	{
		int count=0;
		int mm=INT_MIN;
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j])
				count++;
			else
			{
				if(count>mm)
				{
					mm=count;
				}
				count=0;
			}
		}
		if(count>mm)
		{
			mm=count;
		}
		arr1[i]=mm;
	}
  // for(int i=0;i<n;i++)
  // {
  //   cout<<arr1[i]<<endl;
  // }
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		a=a-1;
		b=b-1;
		arr[a][b]^=1;
    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<m;j++)
    //   {
    //     cout<<arr[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    // cout<<endl;
		int count=0;
		int mm=INT_MIN;
		for(int j=0;j<m;j++)
		{
			if(arr[a][j])
				count++;
			else
			{
				if(count>mm)
				{
					mm=count;
				}
				count=0;
			}
		}
		if(count>mm)
		{
			mm=count;
		}
		arr1[a]=mm;
    //cout<<arr1[a]<<endl;
		cout<<*max_element(arr1,arr1+n)<<endl;
	}
	return 0;
}