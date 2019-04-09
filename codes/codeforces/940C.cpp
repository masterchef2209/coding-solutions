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


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	set<char>x;
	for(int i=0;i<n;i++)
	{
		x.insert(s[i]);
	}
	if(k>n)
	{
		cout<<s;
		int temp=k-n;
		while(temp--)
		{
			cout<< *x.begin();
		}
	}
	else if(k<=n)
	{
		int po=k-1;
		while(po>=0 && s[po]==(*prev(x.end())))
		{
			po--;
		}
		for(int i=0;i<k;i++)
		{
			if(i==po)
			{
				auto it=x.find(s[po]);
				it++;
				cout<< *it;
			}
			else if(i>po)
			{
				cout<< (*x.begin());
			}
			else
			{
				cout<<s[i];
			}
		}
	}
	return 0;
}