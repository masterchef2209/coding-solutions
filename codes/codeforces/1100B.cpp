#include<bits/stdc++.h>
using namespace std;

queue<int>q;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>ans(m,0);
	vector< deque<int> >vv(n+1);
	for(int u=0;u<m;u++)
	{
		int a;
		cin>>a;
		vv[a].push_back(u);
	}
	for(int j=0;j<m;j++)
	{
		int temp=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			if(vv[i].empty())
			{
				goto label;
			}
			//cout<<vv[i].front()<<endl;
			temp=max(temp,vv[i].front());
			vv[i].pop_front();
		}
		ans[temp]=1;
	}
	label:;
	for(int i=0;i<m;i++)
		cout<<ans[i];
return 0;
}