#include<bits/stdc++.h>
using namespace std;
//tle
int graph[100][100];
char ans[100][100];
int n;
vector< vector<int> >li(100);
//tle(maybe wa)
void dfs(int i,vector<int>&parent)
{
	if(li[i].empty())
	{
		li[i]=parent;
	}
	else
	{
		vector<int>temp;
		set_intersection(parent.begin(),parent.end(),li[i].begin(),li[i].end(),back_inserter(temp));
		li[i]=temp;
	}
	for(int j=0;j<n;j++)
	{
		if(graph[i][j]==1 && !binary_search(parent.begin(),parent.end(),j) && i!=j)
		{
			vector<int>parent1(parent.begin(),parent.end());
			parent1.emplace_back(i);
			dfs(j,parent1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int ca=1;ca<=t;ca++)
	{
		li.clear();
		cin>>n;
		if(n==1)
		{
		    int g;
		    cin>>g;
		    cout<<"Case "<<ca<<":"<<endl;
		    cout<<"+-+"<<endl<<"|Y|"<<endl<<"+-+"<<endl;
		    continue;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>graph[i][j];
			}
		}
		vector<int>v;
		dfs(0,v);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
					ans[i][j]='Y';
				else
					ans[i][j]='N';
			}
		}
		for(int i=0;i<n;i++)
		{
			for(unsigned int j=0;j<li[i].size();j++)
			{
				ans[li[i][j]][i]='Y';
			}
		}
		cout<<"Case "<<ca<<":"<<endl;
		for(int i=0;i<2*n+1;i++)
		{
		    if(i%2==0)
			    for(int k=0;k<2*n-1;k++)
			    {
			        if(k==0)
			            cout<<"+";
			        cout<<"-";
			        if(k==2*n-2)
			            cout<<"+"<<endl;
			    }
			  else
			for(int j=0;j<n;j++)
			{
				    cout<<"|"<<ans[(i-1)/2][j];
				    if(j==n-1)
				        cout<<"|"<<endl;
			}
		}
	}
return 0;
}