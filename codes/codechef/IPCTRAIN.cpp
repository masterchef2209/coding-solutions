#include<bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		priority_queue< pair<int,int> >pq;
		vector< vector<int> > lis(d+1);
		vector< int > sed(n+1);
		vector< int > t1(n+1);
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			lis[a].emplace_back(i);
			cin>>t1[i]>>sed[i];
		}
		for(int i=1;i<=d;i++)
		{
			for(int j=0;j<lis[i].size();j++)
			{
				pq.push(make_pair( sed[lis[i][j]] , lis[i][j] ) );
			}
			if(!pq.empty())
			{
				int h=pq.top().second;
				//cout<<h<<" "<<t1[h]-1<<endl;
				t1[h]--;
				if(t1[h]==0)
					pq.pop();
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<t1[i]<<" ";
			ans+=((long long)t1[i]*sed[i]);
		}
		cout<<ans<<endl;


	}
return 0;
}