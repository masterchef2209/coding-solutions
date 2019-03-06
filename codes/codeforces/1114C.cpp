#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,b;
	cin>>n>>b;
	ll b1=b;
	map<ll,ll>mm;
	for(int i=2;i<=sqrt(b1);i++)
	{
		while(b1%i==0)
		{
			mm[i]++;
			b1/=i;
		}
	}
	if(b1>1)
	{
		mm[b1]++;
	}
	ll out=LLONG_MAX;
	for(auto &x:mm)
	{
		ll r=x.first,ans=0;
		for(;n/r>=1;r*=(x.first))
		{
			ans+=n/r;

			//not clear why this works
			if(r>(n/x.first))
				break;
		}
		ans/=x.second;
		out=min(out,ans);
	}
	cout<<out;
return 0;
}