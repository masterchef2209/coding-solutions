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
	ll n;
	cin>>n;
	double arr[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll num=*max_element(arr,arr+n);
	int count=0,ans=-1;
	for(ll i=0;i<n;i++)
	{
		if(arr[i]==num)
		{
			count++;
		}
		else
		{
			ans=max(ans,count);
			count=0;
		}
	}
	ans=max(ans,count);
	count=0;
	cout<<ans<<endl;
    return 0;
}