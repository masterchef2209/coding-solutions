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
	ll arr[n+1];
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	cout<<n+1<<endl;
	cout<<2<<" "<<n<<" "<<1<<endl;
	cout<<1<<" "<<n<<" "<<100000<<endl;
	for(int i=2;i<=n;i++)
	{
		cout<<2<<" "<<i-1<<" "<<100000-(i-1)<<endl;
	}
    return 0;
}