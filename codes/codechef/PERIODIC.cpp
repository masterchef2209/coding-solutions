#include<bits/stdc++.h>
using namespace std;
//not accpeted
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n+1],k=0,count=0,impos=0,m1=1,pos=1;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			if(arr[i]!=-1)
			{
				m1=0;
				if(arr[i]!=i)
				{
					pos=0;
				}
			}
		}
		if(m1==1 || pos==1)
		{
			cout<<"inf"<<endl;
			continue;
		}
		if(arr[1]==-1)
		{
			arr[1]=1;
		}
		else if(arr[1]!=1)
		{
			cout<<"impossible"<<endl;
			continue;
		}
		for(int i=2;i<=n;i++)
		{
			if(arr[i]==-1)
			{
				if(i==n)
				{
					if(count>=1)
					{
						if(arr[i-1]+1>k)
							arr[i]=k;
						else
							arr[i]=arr[i-1]+1;
					}
				}
				else
				{
					if(arr[i+1]==2)
					{
						arr[i]=1;
						count++;
						if(count!=1)
						{
							if(k!=arr[i-1])
							{
								impos=1;
								break;
							}
						}
						k=arr[i-1];
					}
					else
					{
						int j=0;
						while(i+j<=n && arr[i+j]==-1)
						{
							j++;
						}
						if(arr[i+j]==j+1)
						{
							arr[i]=1;
							count++;
							if(count!=1)
							{
								if(k!=arr[i-1])
								{
									impos=1;
									break;
								}
							}
							k=arr[i-1];
						}
						else
						{
							if(count>=1)
							{
								if(arr[i-1]+1>k)
									arr[i]=k;
								else
									arr[i]=arr[i-1]+1;
							}
						}
					}
				}
			}
			else if(arr[i]==1)
			{
				count++;
				if(count!=1)
				{
					if(k!=arr[i-1])
					{
						impos=1;
						break;
					}
				}
				k=arr[i-1];
			}
			else
			{
				if(arr[i]!=arr[i-1]+1)
				{
					impos=1;
					break;
				}
				if(count>=1 && arr[i]>k)
				{
					impos=1;
					break;
				}
			}
		}
		if(impos==1)
			cout<<"impossible"<<endl;
		else
		{
			cout<<k<<endl;
		}
	}
return 0;
}