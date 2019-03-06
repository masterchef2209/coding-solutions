#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	string s;
	cin>>s;
	ll n=s.size();
	vector< vector<ll> >temp(10);
	vector<int> visited(100005,0);
	for(int i=0;i<n;i++)
	{
		temp[s[i]-'0'].eb(i);
	}
	queue< pair<ll,ll> >Q;
	Q.push(mp(0,0));
	ll ans=-1;
	while(!Q.empty())
	{
		ll curr=Q.front().first;
		ll dist=Q.front().second;
		visited[curr]=1;
		if(curr==n-1)
		{
			ans=dist;
			break;
		}
		Q.pop();
		ll i=0;
		while(i<temp[s[curr]-'0'].size() )
		{
		    if( !visited[temp[s[curr]-'0'][i]])
			    Q.push(mp(temp[s[curr]-'0'][i],dist+1));
			i++;
		}
		temp[s[curr]-'0'].clear();
		if(curr<n-1 && !visited[curr+1])
			Q.push(mp(curr+1,dist+1));
		if(curr>0 && !visited[curr-1])
			Q.push(mp(curr-1,dist+1));
	}
	cout<<ans<<endl;
    return 0;
}