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
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		char d;
		cin>>a>>b>>d;
		int c=a+b;
		string a1=to_string(a);
		string b1=to_string(b);
		string c1=to_string(c);
		string a2(""),b2(""),c2("");
		for(int i=0;i<(int)a1.size();i++)
		{
			if(a1[i]==d)
				continue;
			else
				a2+=a1[i];
		}
		for(int i=0;i<(int)b1.size();i++)
		{
			if(b1[i]==d)
				continue;
			else
				b2+=b1[i];
		}
		for(int i=0;i<(int)c1.size();i++)
		{
			if(c1[i]==d)
				continue;
			else
				c2+=c1[i];
		}
		int ax,bx,cx;
		ax=stoi(a2);
		bx=stoi(b2);
		cx=stoi(c2);
		if((ax+bx)==cx )
			cout<<"Go ahead"<<endl;
		else
			cout<<"Try again"<<endl;
	}
    return 0;
}