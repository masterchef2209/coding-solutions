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
	ll n;
	cin>>n;
	vector<ll>sweet(n);
	for(int i=0;i<n;i++)
	{
		cin>>sweet[i];
	}
	map<ll,ll>mm;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ll sm=sweet[i]+sweet[j];
			mm[sm]++;
		}
	}
	ll sw=-1;
	for(auto &x:mm)
	{
		if(x.second>sw)
		{
			sw=x.second;
		}
	}
	cout<<sw<<endl;
    return 0;
}