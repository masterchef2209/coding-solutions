#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector< pair<int,int> > v1,v2;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v1.push_back(make_pair(a,b));
		v2.push_back(make_pair(b,a));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	long long ans=0;
	pair<int,int> temp=make_pair(-9090,-9090),temp1=make_pair(-9090,-9090);
	long long c1=1,c2=1,c3=1;
	for(int i=0;i<n;i++)
	{
		if(temp.first==v1[i].first)
		{
			c1++;
		}
		else
		{
			ans+=((c1*(c1-1))/2);
			c1=1;
		}
		temp=v1[i];
		if(temp1.first==v2[i].first)
		{
			c2++;
      if(temp1.second==v2[i].second)
      {
        c3++;
      }
      else
      {
        ans-=((c3*(c3-1))/2);
        c3=1;
      }
		}
		else
		{
			ans+=((c2*(c2-1))/2);
			c2=1;
      ans-=((c3*(c3-1))/2);
        c3=1;
		}
		temp1=v2[i];
	}
  ans+=((c1*(c1-1))/2);
  ans+=((c2*(c2-1))/2);
  ans-=((c3*(c3-1))/2);
	cout<<ans;
return 0;
}