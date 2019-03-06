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
		ll n,b;
		cin>>n>>b;
		priority_queue<ll>pq;
		for(int u=0;u<n;u++)
		{
			ll w,h,p;
			cin>>w>>h>>p;
			if(p<=b)
			{
				pq.push(w*h);
			}
		}
		if(pq.empty())
			cout<<"no tablet"<<endl;
		else
			cout<< pq.top() <<endl;
	}
    return 0;
}