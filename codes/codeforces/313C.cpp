#include<bits/stdc++.h>
using namespace std;

const int NN=2000100;
int arr[NN];
long long sum[NN]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+N,greater<int>());
	sum[0]=arr[0];
	for(int i=1;i<N;i++)
	{
		sum[i]=sum[i-1]+arr[i];
	}
	for(int i=1;i<=N;i*=4)
	{
		ans+=sum[i-1];
	}
	cout<<ans<<endl;
return 0;
}