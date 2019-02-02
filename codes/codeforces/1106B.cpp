#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n,m;
	cin>>n>>m;
	int arr[n],cost[n];
	priority_queue< pair<int,int>, vector<pair<int,int> >,greater<pair<int,int > > >pq;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>cost[i];
		pq.push(make_pair(cost[i],i));
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		int sum=0;
		int demand=min(arr[a],b);
		int remde=b-demand;
		sum+=cost[a]*demand;
		arr[a]-=demand;
		while(!pq.empty() && remde>0)
		{
			int c=pq.top().second;
			int demand1=min(remde,arr[c]);
			sum+=cost[c]*demand1;
			arr[c]-=demand1;
			if(arr[c]==0)
				pq.pop();
			remde-=demand1;
		}
		if(remde!=0)
		    sum=0;
		cout<<sum<<endl;
	}
return 0;
}