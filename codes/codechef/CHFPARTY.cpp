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
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll>fr(n);
		for(int u=0;u<n;u++)
		{
			cin>>fr[u];
		}
		sort(fr.begin(),fr.end());
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(fr[i]>count)
				break;
			count++;
		}
		cout<<count<<endl;
	}
    return 0;
}