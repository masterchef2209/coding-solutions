#include<bits/stdc++.h>
using namespace  std;

int x[100005];
int rem[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    x[n]=1e9;
    int sol=1e9,cnt=0;
    sort(x,x+n);
    for(int i=0;i<m;i++)
    {
        int x1,x2,y;
        cin>>x1>>x2>>y;
        if(x1==1)
        {
            rem[upper_bound(x,x+n+1,x2)-x]++;
            cnt++;
        }
    }
    for(int i=0;i<=n;i++)
    {
        cnt-=rem[i];
        sol=min(sol,cnt+i);
    }
    cout<<sol;
}