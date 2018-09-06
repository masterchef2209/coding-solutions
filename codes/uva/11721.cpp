#include<bits/stdc++.h>
using namespace std;

int dis[1111];
int V[2222],U[2222],W[2222];
vector<int> adj[1111];
int ans[1111];

int main()
{
  int t;
  cin>>t;
  for(int t1=1;t1<=t;t1++)
  {
    int n,m;
    cin>>n>>m;
    for(int j=1;j<=n;j++)
    {
      dis[j]=0;
      adj[j].clear();
      ans[j]=0;
    }
    for(int j=1;j<=m;j++)
    {
      cin>>V[j]>>U[j]>>W[j];
      V[j]++;
      U[j]++;
      adj[U[j]].push_back(V[j]);
    }
    int ok=1;
    for(int iter=1;iter<n && ok;iter++)
    {
      ok=0;
      for(int j=1;j<=m;j++)
      {
        if(dis[V[j]]>dis[U[j]]+W[j])
        {
          dis[V[j]]=dis[U[j]]+W[j];
          ok=1;
        }
      }
    }
    vector<int> cycle;
    for(int i=1;i<=m;i++)
    {
      if(dis[V[i]]>dis[U[i]]+W[i])
      {
        cycle.push_back(V[i]);
        cycle.push_back(U[i]);
      }
    }
    cout<<"Case "<<t1<<": ";
    if(cycle.empty())
    {
      cout<<"impossible"<<endl;
    }
    else
    {
      queue<int> Q;
      for(int i=0;i<cycle.size();i++)
      {
        Q.push(cycle[i]);
      } 
      while(!Q.empty())
      {
        int x=Q.front();
        Q.pop();
        if(ans[x]) continue;
        ans[x]=1;
        for(int i=0;i<adj[x].size();i++)
        {
            Q.push(adj[x][i]);
        }
      } 
      set<int> s;
      for(int j=1;j<=n;j++)
      {
        if(ans[j])
        {
          s.insert(j);
        }
      }
      set<int> :: iterator it;
      for(it=s.begin();it!=s.end();it++)
      {
        cout<<*it-1;
        if(it!=prev(s.end()))
          cout<<" ";
      }
      cout<<endl;
    }
  }
return 0;
}