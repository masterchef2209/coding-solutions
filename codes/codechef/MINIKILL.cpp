#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define SSIZE 1000006
#define eb emplace_back

vector< vector<ll> >adj(SSIZE);
ll outgoing[SSIZE];
ll parent[SSIZE];
int isleaf[SSIZE];

void mark(ll curr)
{
    if(curr==1)
        return;
    isleaf[curr]=1;
    if(adj[parent[curr]].size()==1)
    {
        mark(parent[curr]);
    }
    else
    {
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(ll u=0;u<(n-1);u++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].eb(b);
        parent[b]=a;
        outgoing[a]++;
    }
    for(ll i=1;i<=n;i++)
    {
        if(outgoing[i]==0)
        {
            mark(i);
        }
    }
    queue<ll>Q;
    Q.push(1);
    ll ans=0;
    while(!Q.empty())
    {
        ll curr=Q.front();
        Q.pop();
        if(isleaf[curr])
            continue;
        ll ccount=0;
        for(auto &nei:adj[curr])
        {
            if(isleaf[nei])
                ccount++;
            Q.push(nei);
        }
        ll why=adj[curr].size();
        if(why==ccount)
        {
            ans+=(ccount-1);
        }
        else
        {
            ans+=(ccount);
        }
    }
    cout<<max(1LL,ans);
return 0;
}