#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define SIZE 100005
double PI=3.1415926535897932384626;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll diff[SIZE];
		ll kplus[SIZE],kminus[SIZE];
		for(ll i=0;i<SIZE;i++)
		{
			diff[i]=kplus[i]=kminus[i]=0;
		}
		vector< pair<ll,ll> >op(n);
		for(ll u=0;u<n;u++)
		{
			ll a,b;
			cin>>a>>b;
			a-=1;b-=1;
			diff[a]+=1;
			if(b<SIZE-1)
				diff[b+1]-=1;
			op[u]=mp(a,b);
		}
		ll ans=0,out=LLONG_MIN;
		for(ll i=1;i<SIZE;i++)
		{
			diff[i]=diff[i-1]+diff[i];
		}
		for(ll i=0;i<SIZE;i++)
		{
			if(diff[i]==k)
			{
				ans++;
				kminus[i]=1;
			}
			else if(diff[i]==k+1)
			{
				kplus[i]=1;
			}
		}
		for(ll i=1;i<SIZE;i++)
		{
			kminus[i]+=kminus[i-1];
			kplus[i]+=kplus[i-1];
		}
		for(ll u=0;u<n;u++)
		{
			pair<ll,ll> temp=op[u];
			ll l=temp.first;
			ll r=temp.second;
			ll countk=0,countk1=0;
			if(l==0)
			{
				countk=kminus[r];
				countk1=kplus[r];
			}
			else
			{
				countk=kminus[r]-kminus[l-1];
				countk1=kplus[r]-kplus[l-1];
			}
			out=max(out,ans-countk+countk1);
		}
		cout<<out<<endl;
	}
    return 0;
}