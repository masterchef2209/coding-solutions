#include<bits/stdc++.h>
using namespace std;

int arr[256];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(arr,0,sizeof(arr));
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<s2.size();i++)
		{
			arr[s2[i]]++;
		}
		for(int i=0;i<s1.size();i++)
		{
			arr[s1[i]]--;
		}
		int flag=0;
		for(int i=0;i<256;i++)
		{
			if(arr[i]<0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
return 0;
}