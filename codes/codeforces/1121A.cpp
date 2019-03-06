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
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll>power(n+1),school(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>power[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>school[i];
	}
	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		ll temp;
		cin>>temp;
		for(int j=1;j<=n;j++)
		{
			if(school[j]==school[temp] && power[j]>power[temp])
			{
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}