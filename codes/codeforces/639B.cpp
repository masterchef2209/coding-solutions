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
	ll n,d,h;
	cin>>n>>d>>h;
	if(n==2)
	{
		if(h==1 && d==1)
		{
			cout<<1<<" "<<2<<endl;
			return 0;
		}
		else
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	ll temp1=n-1;
	if(d>2*h || d<h || n-1<d || n-1<h || d==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	ll i=1;
	ll temp;
	temp=h;
	while(temp--)
	{
		cout<<i<<" "<<i+1<<endl;
		temp1--;
		i++;
		if(temp==0)
		    i++;
	}
	temp=d-h;
	if(temp>0)
	{
		cout<<1<<" "<<i<<endl;
		temp--;
		temp1--;
		if(temp==0)
	       i++;
	
	}
	while(temp--)
	{
	    cout<<i<<" "<<i+1<<endl;
	    temp1--;
	    i++;
	    if(temp==0)
	        i++;
	}
	while(temp1--)
	{
		if(d==h)
			cout<<2<<" "<<i<<endl;
		else
			cout<<1<<" "<<i<<endl;
		i++;
	}
    return 0;
}