#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n,q;
	cin>>n>>q;
	ll a[n],b[n];
	memset(b,0,sizeof(b));
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		l-=1;
		r-=1;
		b[l]+=1;
		if(r<n-1)
			b[r+1]-=1;
	}
	for(ll i=1;i<n;i++)
	{
		b[i]=b[i]+b[i-1];
	}
	ll sum=0;
	sort(a,a+n);
	sort(b,b+n);
	
	for(ll i=0;i<n;i++)
	{
		sum+=(a[i]*b[i]);
	}
	cout<<sum<<endl;
	return 0;
}