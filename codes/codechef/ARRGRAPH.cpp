#include<bits/stdc++.h>
using namespace std;

set<int>ss;
//not accepted
void dprime(int a)
{
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			ss.insert(i);
		}
		while(a%i==0)
		{
			a=a/i;
		}
	}
	if(a>1)
	{
		ss.insert(a);
	}
}

int main()
{
  int arr1[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=0;
		cin>>n;
		int arr[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++)
		{
			int f=1;
			set<int>::iterator it,it1;
			for(it=ss.begin();it!=ss.end();it++)
			{
				if(arr[i]% *it==0)
				{
					f=0;
					break;
				}
			}
      if(ss.size()>0)
      {
        if(f==1)
			  {
				  flag=1;
				  break;
			  }
      }
			dprime(arr[i]);
		}
		if(flag==1)
		{
			cout<<0<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			for(int i=0;i<=15;i++)
			{
				if(ss.find(arr1[i])==ss.end())
				{
					arr[1]=arr1[i];
					break;
				}
			}
			cout<<1<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		ss.clear();
	}
return 0;
}