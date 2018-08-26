#include<bits/stdc++.h>
using namespace std;

vector<int> nodes[100001];
vector<int> visited(100001,0);

void dfs(int i,int *no)
{
    visited[i]=1;
    *no=*no+1;
    for(int j=0;j<nodes[i].size();j++)
    {
        if(!visited[nodes[i][j]])
            dfs(nodes[i][j],no);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long ans=0;
        int flag=0;
        int n,m,c_lib,c_road;
        cin>>n>>m>>c_lib>>c_road;
        for(int u=0;u<m;u++)
        {
            int a,b;
            cin>>a>>b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                int no=0;
                dfs(i,&no);
                ans+=c_lib;
                ans+=((no-1)*c_road);
            }
        }
        cout<<min(ans,(long long)n*c_lib)<<endl;
    for(int i=1;i<=n;i++)
    {
      nodes[i].clear();
    }
    fill(visited.begin(),visited.begin()+n+1,0);
    }
return 0;
}

