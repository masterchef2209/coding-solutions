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
	int n;
	cin>>n;
	vector< pair<int,int> >v;
	for(int i=0;i<n;i++)
	{
		int l,r;
		cin>>l>>r;
		v.eb(mp(l,r));
	}
	sort(v.begin(),v.end());
	int k;
	cin>>k;
	int i;
	for(i=0;i<n;i++)
	{
		if(v[i].first > k)
			break;
	}
	cout<< n-(i-1) <<endl;
    return 0;	
}