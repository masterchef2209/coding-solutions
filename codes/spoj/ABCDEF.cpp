#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> inp(n);
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		inp[i]=temp;
	}
	vector<int> lhs,rhs;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				lhs.push_back(inp[i]*inp[j]+inp[k]);
				if(inp[i]!=0)
					rhs.push_back(inp[i]*(inp[j]+inp[k]));
			}
		}
	}
	sort(lhs.begin(),lhs.end());
  int count=0;
  vector<int>::iterator it;
  for(it=rhs.begin();it!=rhs.end();it++)
  {
    vector<int>::iterator l,r;
    l=lower_bound(lhs.begin(),lhs.end(),*it);
    r=upper_bound(lhs.begin(),lhs.end(),*it);
    count+=((r-lhs.begin())-(l-lhs.begin()));
  }
  cout<<count;
return 0;
}
