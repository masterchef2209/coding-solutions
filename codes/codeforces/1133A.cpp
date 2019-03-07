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
	int h1,m1;
	char s1,s2;
	cin>>h1>>s1>>m1;
	int h2,m2;
	cin>>h2>>s2>>m2;
	int time1=h1*60+m1;
	int time2=h2*60+m2;
	int time=(time1+time2)/2;
	int h3,m3;
	h3=time/60;
	m3=time%60;
	printf("%02d:%02d",h3,m3);
    return 0;
}