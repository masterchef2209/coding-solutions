#include<bits/stdc++.h>
using namespace std;

vector<int> students[1001];
vector<int> visited(1001,0);

int ans=0,flag=0;

void dfs(int i)
{
  visited[i]+=1;
  if(visited[i]==2)
  {
    ans=i;
    flag=1;
    return;
  }
  for(int j=0;j<students[i].size();j++)
  {
      dfs(students[i][j]);
      if(flag==1)
        return;
  }
}

int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int temp;
    cin>>temp;
    students[i].push_back(temp);
  }
  for(int i=1;i<=n;i++)
  {
    ans=0,flag=0;
    dfs(i);
    cout<<ans<<" ";
    fill(visited.begin(),visited.begin()+n+1,0);
  }
return 0;
}
