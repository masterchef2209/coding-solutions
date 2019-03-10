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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll changes=0;
		ll zeroes=0,ones=0;
	//	string temp("");
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
				zeroes++;
			else
				ones++;
			if(zeroes>ones)
			{
				zeroes--;
				ones++;
				changes++;
			//	temp+="1";
			}
		//	else
		//	    temp+=s[i];
		}
		cout<<changes<<endl;
		//cout<<temp<<endl;
	}
    return 0;
}