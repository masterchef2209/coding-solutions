#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>v(n,0);
	for(ll i=n-1;i>n/2-1;i--)
	{
		cin>>v[i];
	}
	for(ll i=1;i<n/2;i++)
	{
		ll temp=max(v[i-1],v[n-i-1]-v[n-i]);
		v[i]+=temp;
		v[n-i-1]-=temp;
	}
	for(ll i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
}