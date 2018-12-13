#include<bits/stdc++.h>
using namespace std;

vector< pair<long long, pair< int,int > > >vv;
int n,m;
vector<int> arr,si;

void initialize()
{
	arr.clear();
	si.clear();
	for(int i=0;i<=n;i++)
	{
		arr.push_back(i);
		si.push_back(1);
	}
}

int root(int i)
{
	while(i!=arr[i])
	{
		arr[i]=arr[arr[i]];
		i=arr[i];
	}
return i;
}

bool connected(int a,int b)
{
	return root(a)==root(b);
}

void dsu(int a,int b)
{
	int rootA=root(a);
	int rootB=root(b);
	if(si[rootA]<si[rootB])
	{
		arr[rootA]=arr[rootB];
		si[rootB]+=si[rootA];
	}
	else
	{
		arr[rootB]=arr[rootA];
		si[rootA]+=si[rootB];
	}
}

long long kruskal()
{
	initialize();
	long long cost=0;
	for(int j=0;j<vv.size();j++)
	{
		long long c=vv[j].first;
		int a=vv[j].second.first;
		int b=vv[j].second.second;
		if(!connected(a,b))
		{
			dsu(a,b);
			cost+=c;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!connected(i,i-1))
			return -1;
	}
return cost;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			int bi;
			cin>>bi;
			if(bi==1)
			{
				vv.push_back(make_pair(0,make_pair(0,i)));
			}
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			long long cost;
			cin>>u>>v>>cost;
			vv.push_back(make_pair(cost,make_pair(u,v)));
		}
		sort(vv.begin(),vv.end());
		long long ans=kruskal();
		if(ans==-1)
			cout<<"impossible"<<endl;
		else
			cout<<ans<<endl;
		vv.clear();
	}
return 0;
}