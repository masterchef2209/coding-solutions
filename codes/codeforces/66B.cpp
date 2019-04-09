#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		int count=1;
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j]>arr[j+1])
				break;
			count++;
		}
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]>arr[j-1])
				break;
			count++;
		}
		ans=max(ans,count);
	}
	cout<<ans<<endl;
    return 0;
}