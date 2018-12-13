#include<bits/stdc++.h>
using namespace std;
//using PRIMS
const int MAX = 1e4 + 5;

vector< vector< pair<long long,int> > >mst(MAX);
vector<int> visited(MAX,0);


long long prims(int i)
{
  priority_queue< pair<long long,int>, vector< pair<long long,int> > ,greater< pair<long long,int>  >  > pq;
  long long minCost=0;
  pq.push(make_pair(0,i));
  while(!pq.empty())
  {
    pair< long long,int > p=pq.top();
    pq.pop();
    int x=p.second;
    if(visited[x])
      continue;
    visited[x]=1;
    minCost+=p.first;
    for(int j=0;j<mst[x].size();j++)
    {
      if(!visited[mst[x][j].second])
      {
        pq.push(mst[x][j]);
      }
    }
  }
return minCost;
}

int main()
{
  int n,m;
  cin>>n>>m;
  long long weight,minCost;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b>>weight;
    mst[a].push_back(make_pair(weight,b));
    mst[b].push_back(make_pair(weight,a));
  }
  int start;
  cin>>start;
  minCost=prims(start);
  cout<<minCost<<endl;
return 0;
}