#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>row;
vector<int>column;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		row.clear();
		column.clear();
		set<int>a,b;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=k;i++)
		{
			int r,c;
			cin>>r>>c;
			row.emplace_back(r);
			column.emplace_back(c);
		}
		sort(row.begin(),row.end());
		sort(column.begin(),column.end());
		for(int i=1;i<=n;i++)
		{
			if(!binary_search(row.begin(),row.end(),i))
			{
				a.insert(i);
			}
			if(!binary_search(column.begin(),column.end(),i))
			{
				b.insert(i);
			}
		}
		int kk=n-max(column.size(),row.size());
		auto i1=a.begin();
		auto i2=b.begin();
		cout<<kk<<" ";
		while(kk--)
		{
			cout<<*i1<<" "<<*i2<<" ";
			i1++;
			i2++;
		}
		cout<<endl;
	}
return 0;
}