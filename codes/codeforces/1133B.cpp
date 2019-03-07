#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	ll temp1[110];
	memset(temp1,0,sizeof(temp1));
	for(ll i=0;i<n;i++)
	{
		ll temp;
		cin>>temp;
		temp1[temp%k]++;
	}
	ll ans=0;
	if(temp1[0]&1)
	{
		ans+=(temp1[0]-1);
	}
	else
	{
		ans+=(temp1[0]);
	}
	ll i=1,j=k-1;
	while(i<j)
	{
		ans+=(2*min(temp1[i],temp1[j]));
		i++;
		j--;
	}
	if(i==j)
	{
		if((i+j)%k==0)
		{
			if(temp1[i]&1)
			{
				ans+=(temp1[i]-1);
			}
			else
			{
				ans+=(temp1[i]);
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}