#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define INF 1000000007

int n,m;
int oldman[101];
int size[101];
int setsize;

vector< pair<int,ii> >edges;

void initi()
{
	setsize=n;
	for(int i=0;i<=n;i++)
	{
		oldman[i]=i;
		size[i]=1;
	}
}

int root(int i)
{
	while(i!=oldman[i])
	{
		oldman[i]=oldman[oldman[i]];
		i=oldman[i];
	}
return i;
}

void dsu_union(int a,int b)
{
	int oldA=root(a);
	int oldB=root(b);
	if(size[oldA]<size[oldB])
	{
		oldman[oldA]=oldman[oldB];
		size[oldB]+=size[oldA];
	}
	else
	{
		oldman[oldB]=oldman[oldA];
		size[oldA]+=size[oldB];
	}
	setsize--;
}

int secondmst(int S,int D)
{
	initi();
	int sum=0;
	for(int i=0;i<edges.size();i++)
	{
		int a=edges[i].second.first;
		int b=edges[i].second.second;
		if(a==S && b==D)
			continue;
		if(root(a)!=root(b))
		{
			dsu_union(a,b);
			sum+=edges[i].first;
		}
	}
	if(setsize!=1)
		return INF;
return sum;
}

vector< pair<int,ii> > kruskal()
{
	initi();
	vector< pair<int,ii> >MST;
	int sum=0;
	for(int i=0;i<edges.size();i++)
	{
		int a=edges[i].second.first;
		int b=edges[i].second.second;
		if(root(a)!=root(b))
		{
			dsu_union(a,b);
			sum+=edges[i].first;
			MST.emplace_back(make_pair(edges[i].first,make_pair(a,b)));
		}
	}
return MST;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		edges.clear();
		for(int u=0;u<m;u++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			edges.emplace_back(make_pair(c,make_pair(a,b)));
		}
		sort(edges.begin(),edges.end());
		auto MST=kruskal();

		int s1=0,s2=INF;

		for(auto it=MST.begin();it!=MST.end();it++)
		{
			s1+=it->first;
			s2=min(s2,secondmst(it->second.first,it->second.second));
		}
		if(s2==INF)
			cout<<s1<<" "<<s1<<endl;
		else
			cout<<s1<<" "<<s2<<endl;
	}
return 0;
}