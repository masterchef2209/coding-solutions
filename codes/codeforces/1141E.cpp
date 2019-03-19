#include <bits/stdc++.h>

//not accepted

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
	ll H,n;
	ll ans=-1;
	cin>>H>>n;
	ll H1=H;
	vector<ll>haha(n);
	ll delta=0;
	for(int i=0;i<n;i++)
	{
		cin>>haha[i];
		delta+=haha[i];
		H1+=haha[i];
		if(ans==-1 && H1<=0)
		{
			ans=i+1;
		}
	}
	if(ans!=-1)
	{
		cout<<ans<<endl;
		return 0;
	}
	if(delta>=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	//cout<<ans<<delta<<endl;
	ll x=H/abs(delta);
	ll y=H%abs(delta);
	if(x!=0)
	{
	    x--;
	    y+=(-delta);
	}
	//cout<<x<<" "<<y<<endl; 
	ll ans1=x*n;
	//cout<<ans1<<endl;
	for(ll i=0;i<n;i++)
	{
		y+=haha[i];
		if(y<=0)
		{
			cout<<ans1+(i+1)<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
    return 0;
}