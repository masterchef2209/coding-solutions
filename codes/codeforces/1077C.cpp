#include<bits/stdc++.h>
using namespace std;

int main()
{
	long n;
	cin>>n;
	vector<pair< long,long > >arr(n+1);
	long sum=0;
	for(long i=1;i<=n;i++)
	{
		long k;
    cin>>k;
    arr[i]=make_pair(k,i);
    sum+=k;
	}
	sort(arr.begin()+1,arr.end());
	vector<long>nice;
	for(long i=1;i<n;i++)
	{
		if(sum-arr[i].first-arr[n].first==arr[n].first)
			nice.push_back(arr[i].second);
	}
	if(sum-arr[n].first-arr[n-1].first==arr[n-1].first)
		nice.push_back(arr[n].second);
	cout<<nice.size()<<endl;;
	for(long i=0;i<nice.size();i++)
	{
		cout<<nice[i]<<" ";
	}
return 0;
}