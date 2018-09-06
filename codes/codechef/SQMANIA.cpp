#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{
	ll n;
	cin>>n;
	if(n==1)
	{
		ll l;
		cin>>l;
		cout<<4*l;
		exit(0);
	}
	ll ans=0;
	ll last;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		ans+=(5*x);
		last=x;
	}
	ans-=last;
	for(ll i=0;i<n-1;i++)
	{
		ll b;
		cin>>b;
		ans+=b;
	}
	cout<<ans;
return 0;
}