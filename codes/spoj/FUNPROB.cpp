#include <bits/stdc++.h>
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
	double n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			break;
		if(n>m)
			cout<<"0.000000"<<endl;
		else
		{
			cout<<fixed<<setprecision(6)<<(m-n+1)/(m+1)<<endl;
		}
	}
    return 0;
}