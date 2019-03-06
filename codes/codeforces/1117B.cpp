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
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr.rbegin(),arr.rend());
	ll ans=0;
	if(m<=k)
	{
		ans+=arr[0]*k;
	}
	else
	{
	    if((m+1)%(k+1)==0)
	    {
	        ll temp=(m+1)/(k+1);
	        ans=arr[0]*k*temp+arr[1]*(temp-1);
	    }
	    else
	    {
	        ll yo=m/(k+1);
	        ll rem=m%(k+1);
	        ans=arr[0]*k*yo+arr[1]*yo+rem*arr[0];
	    }
	}
	cout<<ans<<endl;
    return 0;
}