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

map<char,deque<ll> >m1,m2;
ll ans=0;
vector< pair<ll,ll> >ans1;

void work(char a,char b)
{
	ll temp=min(m1[a].size(),m2[b].size());
	ans+=temp;
	while(temp--)
	{
		ans1.eb(mp(m1[a].front(),m2[b].front()));
		m1[a].pop_front();
		m2[b].pop_front();
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	string l,r;
	cin>>l>>r;
	for(int i=0;i<n;i++)
	{
		m1[l[i]].pb(i+1);
		m2[r[i]].pb(i+1);
	}
	for(char x='a';x<='z';x++)
	{
		work(x,x);
	}
	for(char x='a';x<='z';x++)
	{
		work('?',x);
	}
	for(char x='a';x<='z';x++)
	{
		work(x,'?');
	}
	for(char x='a';x<='z';x++)
	{
		work('?','?');
	}
	cout<<ans<<endl;
	for(auto &no:ans1)
	{
	    cout<<no.f<<" "<<no.s<<endl;
	}
    return 0;
}