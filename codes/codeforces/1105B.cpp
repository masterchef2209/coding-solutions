#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	int arr[26]={0};
	cin>>n>>k;
	string s;
	cin>>s;
	int ans=0;
	if(k==1)
	{
	    for(int i=0;i<n;i++)
	    {
	        arr[s[i]-'a']++;
	    }
	}
	else
	{
	    for(int i=0;i<n;)
	{
	   // cout<<"new"<<endl;
		int flag=0;
		int temp=0;
		char tt;
		for(int j=1;j<k;j++)
		{
		    //cout<<i+j<<" ";
		    tt=s[i+j];
		    if(i+j>=n)
		    {
		        goto out;
		    }
			if(s[i+j]!=s[i+j-1])
			{
				flag=1;
				temp=i+j;
				break;
			}
		}
	//	cout<<flag<<" ";
		if(flag==0)
		{
		    arr[tt-'a']++;
			ans++;
			i+=(k);
		}
		else
		{
			i=temp;
		}
	}
	out:;
	}
	cout<< *max_element(arr,arr+26) <<endl;
return 0;
}