#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>bag;
set<ll>s;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	ll n,a,b;
	while(cin>>n>>a>>b)
	{
    if(n==0)
			break;
		bag.clear();
		s.clear();
		set<ll>::iterator it;
		ll x=0;
		bag.emplace_back(x);
		s.insert(x);
		while(1)
		{
			x=((((a%n)*(x%n))%n*(x%n))%n+b%n)%n;
			it=s.find(x);
			if(it!=s.end())
				break;
			s.insert(x);
      //cout<<x<<endl;
			bag.emplace_back(x);
		}
    //cout<<*it<<endl;
		vector<ll>::iterator it1=find(bag.begin(),bag.end(),*it);
		cout<<n-(bag.size()-(it1-bag.begin()))<<endl;
	}
	return 0;
}