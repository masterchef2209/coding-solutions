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

int m;
vector<int>nodes;
vector<int>ans;

int done=0;

void dfs(int balance,int lastweight,int steps)
{
	if(done)
		return;
	if(lastweight>=1 && lastweight<=10)
		ans.eb(lastweight);
	if(steps==m)
	{
		done=1;
		return;
	}
	for(auto &x:nodes)
	{
		if(x==lastweight)
			continue;
		int val;
		if(steps&1)
		{
			val=balance-x;
		}
		else
		{
			val=balance+x;
		}
		if(abs(balance)>=x)
			continue;
		dfs(val,x,steps+1);
		if(done)
			return;
	}
	if(!ans.empty())
		ans.pop_back();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	for(int i=1;i<=10;i++)
	{
		char x;
		cin>>x;
		if(x=='1')
		{
			nodes.eb(i);
		}
	}
	cin>>m;
	dfs(0,0,0);
	if(done==0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(auto &x:ans)
	{
		cout<<x<<" ";
	}
    return 0;
}