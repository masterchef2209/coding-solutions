#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	string line;
	while(getline(cin,line))
	{
		if(line.empty())
			break;
		vector<ll> c,x;
		ll val;
		istringstream iii(line);
		while(iii>>val)
		{
			c.emplace_back(val);
		}
		string line2;
		getline(cin,line2);
		istringstream iii2(line2);
		while(iii2>>val)
		{
			x.emplace_back(val);
		}
		for(ll g=0;g<x.size();g++)
		{
			ll ans=0;
			for(ll i=c.size()-1,ex=0;i>=0;i--,ex++)
			{
				ans+=(c[i]*pow(x[g],ex));
			}
			cout<<ans;
			if(g!=x.size()-1)
				cout<<" ";
		}
		cout<<endl;
	}
return 0;
}