#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
long long size[MAX];
int arr[MAX];
pair< long long, pair<int,int> > p[MAX];
int n,m;
void initialize()
{
  for(int i=0;i<MAX;i++)
  {
    arr[i]=i;
    size[i]=1;
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

void dsu(int a,int b)
{
  int rootA=root(a);
  int rootB=root(b);
  if(size[rootA]<size[rootB])
  {
    arr[rootA]=arr[rootB];
    size[rootB]+=size[rootA];
  }
  else
  {
    arr[rootB]=arr[rootA];
    size[rootA]+=size[rootB];
  }
}

long long kruskal()
{
  long long minCost=0;
  for(int i=0;i<m;i++)
  {
    int a=p[i].second.first;
    int b=p[i].second.second;
    long long cost=p[i].first;
    if(root(a)!=root(b))
    {
      dsu(a,b);
      minCost+=cost;
    }
  }
return minCost;
}

int main()
{
  initialize();
  long long weight,minCost;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b>>weight;
    p[i]=make_pair(weight,make_pair(a,b));
  }
  sort(p,p+m);
  minCost=kruskal();
  cout<<minCost<<endl;
  return 0;
}