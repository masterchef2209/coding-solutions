#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long arr[10];
	cin>>arr[0];
	long long aa=abs(arr[0]-100);
	int ans=0;
	for(int i=1;i<10;i++)
	{
		cin>>arr[i];
		arr[i]+=arr[i-1];
		if(abs(arr[i]-100)<=aa)
		{
      if(abs(arr[i]-100)==aa && arr[i]<arr[ans])
        continue;
			aa=abs(arr[i]-100);
			ans=i;
		}
	}
	cout<<arr[ans]<<endl;
return 0;
}