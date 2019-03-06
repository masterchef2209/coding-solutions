#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;


ll merge(ll arr[],ll l,ll r,ll m)
{
	ll i,j,k;
	ll n=r-l+1;
	ll temp[n];
	ll count=0;
	i=l;j=m+1;k=0;
	while((i<=m) && (j<=r))
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
			count+=(m+1-i);
		}
	}
	while(i<=m)
		temp[k++]=arr[i++];
	while(j<=r)
		temp[k++]=arr[j++];
	for(int i=0;i<n;i++)
	{
		arr[l+i]=temp[i];
	}
	return count;
}

ll mergesort(ll arr[],ll l,ll r)
{
	ll ans=0;
	if(l<r)
	{
		int m=l+(r-l)/2;
		ans+=mergesort(arr,l,m);
		ans+=mergesort(arr,m+1,r);
		ans+=merge(arr,l,r,m);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<mergesort(arr,0,n-1)<<endl;
	}
    return 0;
}