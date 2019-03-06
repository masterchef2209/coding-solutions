#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	vector< pair<int,int> >arr(n+1);
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		arr[i]=make_pair(a,i);
	}
	auto it=arr.rend();
	it--;
	sort(arr.rbegin(),it);
	vector<int>indices;
	int sum=0;
	for(int i=1;i<=m*k;i++)
	{
		sum+=(arr[i].first);
		indices.emplace_back(arr[i].second);
	}
	sort(indices.begin(),indices.end());
	cout<<sum<<endl;
	int count=0;
	for(int i=0;i<indices.size();i++)
	{
	    if(count==k-1)
	        break;
		if((i+1)%m==0)
		{
			cout<<indices[i]<<" ";
			count++;
		}
	}
return 0;
}