#include<bits/stdc++.h>
using namespace std;

int main()
{
	long n,m,d;
	cin>>n>>m>>d;
	long arr[n+1],arr1[n+1],visited[n+1];
	memset(visited,0,sizeof(visited));
	for(long i=1;i<=n;i++)
	{
		cin>>arr[i];
		arr1[i]=arr[i];
	}
	sort(arr+1,arr+n+1);
	long day=1,day1=1;
	long inn=1;
	long x;
	long count=0;
	unordered_map<long long int,long long int> ans;
	while(count!=n)
	{
    if(inn>n)
      break;
		x=arr[inn];
    //cout<<x<<endl;
		ans[x]=day;
    visited[inn]=1;
    day1=day;
		count++;
		x+=d;
		long *ptr=upper_bound(arr+1,arr+n+1,x);
    //cout<<*ptr<<endl;
    inn=ptr-arr;
    //cout<<inn<<endl;
    if(inn>n)
		{
			day++;
			for(long i=1;i<=n;i++)
			{
				if(!visited[i])
				{
					inn=i;
					break;
				}
			}
		}
		while(inn<=n && visited[inn])
		{
			inn++;
		}
    if(inn>n)
		{
			day++;
			for(long i=1;i<=n;i++)
			{
				if(!visited[i])
				{
					inn=i;
					break;
				}
			}
		}
    //cout<<inn<<endl;
	}
  cout<<day1<<endl;
	for(long i=1;i<=n;i++)
	{
		cout<<ans[arr1[i]]<<" ";
	}
	return 0;
}