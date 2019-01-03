#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
//tle
int n,m;
int arr[102][102];
int visited[102][102];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
inline bool ingrid(pii &x)
{
	return (x.first>0 && x.first<=n && x.second>0 && x.second<=m);
}

int bfs(pii &s)
{
	if(visited[s.first][s.second]==1)
		return 0;
	queue<pii>Q;
	vector<int>bag;
	Q.push(s);
	while(!Q.empty())
	{
		pii u=Q.front();
		Q.pop();
		visited[u.first][u.second]=1;
		int flag=1;
		bag.emplace_back(arr[u.first][u.second]);
		int mm=INT_MAX;
		for(int a=0;a<4;a++)
		{
			pii v=pii(u.first+dx[a],u.second+dy[a]);
      if(!ingrid(v))
        {
        	flag=0;
        	break;
        }
			if(visited[v.first][v.second]==0 && arr[v.first][v.second]<arr[u.first][u.second])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			for(int a=0;a<4;a++)
			{
				pii v=pii(u.first+dx[a],u.second+dy[a]);
				if(visited[v.first][v.second]==0)
				{
					if(arr[v.first][v.second]<mm)
					{
						mm=arr[v.first][v.second];
					}
				}
			}
			for(int a=0;a<4;a++)
			{
				pii v=pii(u.first+dx[a],u.second+dy[a]);
				if(visited[v.first][v.second]==0)
				{
					if(arr[v.first][v.second]==mm)
					{
						Q.push(pii(v.first,v.second));
					}
				}
			}
		}
	}
	int MM=*max_element(bag.begin(),bag.end());
	int s1=0;
	for(int i=0;i<bag.size();i++)
	{
		s1+=(MM-bag[i]);

	}
	return s1;
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
		
		vector<pii>vv;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				visited[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>arr[i][j];
				
			}
		}
		
    	for(int i=1;i<=n;i++)
    	{
      		for(int j=1;j<=m;j++)
      		{
        		int flag=1;
				for(int a=0;a<4;a++)
				{
          			pii o=pii(i+dx[a],j+dy[a]);
					if(!ingrid(o) || arr[o.first][o.second]<arr[i][j])
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					vv.emplace_back(pii(i,j));
				}
      		}
    	}

		long long sum=0;
		for(int a=0;a<vv.size();a++)
		{

			sum+=bfs(vv[a]);

			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					visited[i][j]=0;
				}
			}
		}
		cout<<sum<<endl;
	}
return 0;
}