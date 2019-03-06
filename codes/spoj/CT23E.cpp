#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

vector< vector<ll> >adj(1000007);
vector<ll>visited(1000007,0);
//not accepted
ll ss=0;

void dfs(ll a)
{
	visited[a]=1;
	ss++;
	for(auto &b:adj[a])
	{
		if(!visited[b])
		{
			dfs(b);
		}
	}
}

ll func(ll N) 
{ 
    //  base case 2 = 1 + 1 
    if (N == 2) 
        return 1; 
  
    //  base case 3 = 2 + 1 
    if (N == 3) 
        return 2; 
  
    ll maxProduct; 
  
    //  breaking based on mod with 3 
    switch (N % 3) 
    { 
        // If divides evenly, then break into all 3 
        case 0: 
            maxProduct = pow(3, N/3); 
            break; 
  
        // If division gives mod as 1, then break as 
        // 4 + power of 3 for remaining part 
        case 1: 
            maxProduct = 2 * 2 * pow(3, (N/3) - 1); 
            break; 
  
        // If division gives mod as 2, then break as 
        // 2 + power of 3 for remaining part 
        case 2: 
            maxProduct = 2 * pow(3, N/3); 
            break; 
    } 
    return maxProduct; 
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	for(int u=0;u<n-1;u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	vector<ll>bag;
	for(ll i=1;i<=n;i++)
	{
		if(visited[i])
			continue;
		ss=0;
		dfs(i);
		bag.eb(ss);
	}
	
 	ll ans=1;
	for(auto &o:bag)
	{
	    //cout<<o<<" ";
		ans*=func(o);
	}
 	cout<<ans<<endl;
    return 0;
}