#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ppi pair<int,pii>

char arr[26][26];
int visited[26][26];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int w,h;

inline bool ingrid(pii &x)
{
	return x.first>=0 && x.first<h && x.second>=0 && x.second<w;
}

int bfs(pii &s)
{
	priority_queue<ppi,vector<ppi>,greater<ppi> >Q;
	Q.push(ppi(0,s));
	while(!Q.empty())
	{
		pii u=Q.top().second;
		int w=Q.top().first;
		Q.pop();
    //cout<<arr[u.first][u.second]<<endl;
    visited[u.first][u.second]=1;
		for(int i=0;i<4;i++)
		{
			pii v=pii(u.first+dx[i],u.second+dy[i]);
			if(ingrid(v) && arr[v.first][v.second]!='X' && visited[v.first][v.second]==0)
			{
				if(arr[v.first][v.second]=='D')
				{
					return w;
				}
				else
				{
					Q.push(ppi(w+(arr[v.first][v.second]-'0'),v));
				}
			}
		}
	}
	return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	cin>>w>>h;
	while(w!=0 || h!=0)
	{
    for(int i=0;i<h;i++)
    {
      for(int j=0;j<w;j++)
      {
        visited[i][j]=0;
      }
    }
		int sx,sy,dxx,dyy;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin>>arr[i][j];
        //cout<<arr[i][j];
				if(arr[i][j]=='S')
				{
					sx=i,sy=j;
				}
				else if(arr[i][j]=='D')
				{
					dxx=i,dyy=j;
				}
			}
      //cout<<endl;
		}
    	pii st=pii(sx,sy);
		cout<<bfs(st)<<endl;
		cin>>w>>h;
	}
return 0;
}