#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n;
	cin>>n;
	vector< pair<int,int> >vv;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		vv.emplace_back(make_pair(a,b));
	}
	sort(vv.begin(),vv.end());
	int cp=-1;
	for(auto it=vv.begin();it!=vv.end();it++)
	{
		if(it->first >= cp && it->second >=cp)
		{
			cp=min(it->first,it->second);
		}
		else
		{
			if(it->first>= cp)
			{
				cp=it->first;
			}
			else if(it->second>=cp)
			{
				cp=it->second;
			}
		}
		
	}
	cout<<cp;
return 0;
}