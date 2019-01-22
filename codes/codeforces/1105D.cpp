#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
//not accepted
int n,m,p;
char grid[1001][1001];
vector<int> sp(10);

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

inline bool ingrid(pii &a)
{
	return (a.first>=0 && a.second>=0 && a.first<n && a.second<m);
}

bool isgood(pii &b)
{
	for(int i=0;i<4;i++)
	{
		pii c={b.first+dr[i],b.second+dc[i]};
		if(ingrid(c))
		{
			if(grid[c.first][c.second]=='.')
				return true;
		}
	}
return false;
}

void bfs(vector< vector<pii> >&s)
{
	int count[10];
	memset(count,0,sizeof(count));
	while(1)
	{
		bool flag=false;
		for(int i=1;i<=p;i++)
		{
			priority_queue<pip>Q;
			for(int j=0;j<s[i].size();j++)
			{
				pii temp=s[i][j];
				if(isgood(temp))
				{
					flag=true;
					Q.push({sp[i],{temp.first,temp.second}});
				}
			}
			s[i].clear();
			while(!Q.empty())
			{
				pii u=Q.top().second;
				int speed=Q.top().first;
				Q.pop();
				for(int k=0;k<4;k++)
				{
					pii v=pii(u.first+dr[k],u.second+dc[k]);
					if(ingrid(v) && grid[v.first][v.second]=='.')
					{
						grid[v.first][v.second]=(char)('0'+i);
						s[i].emplace_back(make_pair(v.first,v.second));
						if(speed>1 && isgood(v))
							Q.push({speed-1,{v.first,v.second}});
					}
				}
			}
		}
		if(!flag)break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			//cout<<grid[i][j]<<" ";
			if(isdigit(grid[i][j]))
				count[grid[i][j]-'0']++;
		}
		//cout<<endl;
	}
	for(int u=1;u<=p;u++)
	{
		cout<<count[u]<<" ";
	}
}

signed main()
{
	cin>>n>>m>>p;
	for(int i=1;i<=p;i++)
	{
		cin>>sp[i];
	}
	vector< vector<pii> >s(p+1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
			if(isdigit(grid[i][j]))
			{
				pii temp=pii(i,j);
				s[grid[i][j]-'0'].emplace_back(temp);
			}
		}
	}
	bfs(s);
	return 0;
}