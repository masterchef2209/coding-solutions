#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin>>n;
	vector<long long>vv;
	for(long long i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			vv.push_back(i);
		}
		while(n%i==0)
		{
			n=n/i;
		}
	}
	if(n>1)
		vv.push_back(n);
	vector<long long>::iterator it;
	long long ans=1;
	for(it=vv.begin();it!=vv.end();it++)
	{
		ans*=(*it);
	}
	cout<<ans;

return 0;
}