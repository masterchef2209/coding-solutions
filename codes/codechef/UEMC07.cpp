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
	ll n;
	cin>>n;
	priority_queue<ll>pq;
	for(ll i=0;i<n;i++)
	{
		ll temp;
		cin>>temp;
		pq.push(temp);
	}
	ll one,two;
	while(!pq.empty())
	{
		one=pq.top();
		pq.pop();
		if(pq.empty())
		{
			break;
		}
		two=pq.top();
		pq.pop();
		ll temp=((one%mod)*(two%mod))%mod;
		pq.push(temp);
	}
	cout<<one<<endl;
    return 0;
}